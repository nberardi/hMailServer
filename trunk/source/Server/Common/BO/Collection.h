// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

#pragma once

namespace HM
{
   template <class T, class P>
   class Collection
   {
   public:

      virtual ~Collection<T, P>() {};

      virtual void AddItem(boost::shared_ptr<T> pObject)
      {
         vecObjects.push_back(pObject);
      }

      bool XMLStore(XNode *pParentNode, int iBackupOptions);
      bool XMLLoad(XNode *pBackupNode, int iRestoreOptions);

      boost::shared_ptr<T> GetItem(unsigned int Index) const;
      boost::shared_ptr<T> GetItemByDBID(unsigned __int64 DBID) const;
      boost::shared_ptr<T> GetItemByDBID(unsigned __int64 DBID, int &foundIndex) const;
      boost::shared_ptr<T> GetItemByName(const String &sName) const;

      bool DeleteItemByDBID(__int64 iDBID);
      bool DeleteItem(unsigned int Index);
      virtual bool DeleteAll();

      vector<boost::shared_ptr<T> > &GetVector() {return vecObjects; }
      const vector<boost::shared_ptr<T> > &GetConstVector() const {return vecObjects; }

      int GetCount() const {return (int) vecObjects.size(); }


   protected:

      virtual String GetCollectionName() const = 0;

      // Called before saved to XML
      virtual void PostStoreObject(boost::shared_ptr<T> pObject, XNode *node) {};

      // Called before save in DB
      virtual bool PreSaveObject(boost::shared_ptr<T> pObject, XNode *node) {return true; }
      
      bool _DBLoad(const String &sSQL);
      bool _DBLoad(const SQLCommand &command);

      CriticalSection _lock;

      vector<boost::shared_ptr<T> > vecObjects;
   };


   template <class T, class P> 
   bool Collection<T,P>::XMLStore(XNode *pParentNode, int iBackupOptions)
   {
      CriticalSectionScope scope(_lock);

      if (vecObjects.size() == 0)
         return true;

      XNode *pCollNode = pParentNode->AppendChild(GetCollectionName());

      boost_foreach(boost::shared_ptr<T> pItem, vecObjects)
      {
         if (!pItem->XMLStore(pCollNode, iBackupOptions))
            return false;
         
         unsigned int objectCount = pCollNode->GetChildCount();
         XNode *pElem = pCollNode->GetChild(objectCount-1);

         PostStoreObject(pItem, pElem);
      }

      return true;
   }

   template <class T, class P> 
   bool Collection<T,P>::XMLLoad(XNode *pBackupNode, int iRestoreOptions)
   {
      CriticalSectionScope scope(_lock);

      // First delete the currently existing items.
      if (!DeleteAll())
         return true;

      XNode *pCollNode = pBackupNode->GetChild(GetCollectionName());

      if (pCollNode)
      {
         for (int i = 0; i < pCollNode->GetChildCount(); i++)
         {
            XNode *pChildNode = pCollNode->GetChild(i);

            boost::shared_ptr<T> pItem = boost::shared_ptr<T>(new T);
            if (!pItem->XMLLoad(pChildNode, iRestoreOptions))
               return false;
            
            // Fire the PreSave event. In this event, parent collections can set
            // properties to the child objects. This is done if the child object
            // isn't aware of some property of itself.
            if (PreSaveObject(pItem, pChildNode))
            {
               String result; 
               if (!P::SaveObject(pItem, result))
               {
                  // Handle failure..
                  String message;
                  message.Format(_T("Failed to save object %s. Error: %s"), pItem->GetName(), result);

                  ErrorManager::Instance()->ReportError(ErrorManager::Critical, 5212, "Collection::XMLLoad", message);
                  return false;
               }

               // Load sub items to this object. Needs to be done
               // after the parent object has been saved in the
               // database, so that the child items can have their
               // database ParentID's properly assigned.
               if (!pItem->XMLLoadSubItems(pChildNode, iRestoreOptions))
                  return false;
            }

            // Add it to the collection.
            vecObjects.push_back(pItem);
         }
      }

      return true;
   }

   template <class T, class P> 
   boost::shared_ptr<T> Collection<T,P>::GetItem(unsigned int Index) const
   {
      CriticalSectionScope scope(_lock);

      boost::shared_ptr<T> pRet;

      if (Index >= 0 && Index < vecObjects.size())
         pRet = vecObjects[Index];

      return pRet;
   }

   template <class T, class P> 
   boost::shared_ptr<T> Collection<T,P>::GetItemByDBID(unsigned __int64 DBID) const
   {
      CriticalSectionScope scope(_lock);

      int index = 0;
      return GetItemByDBID(DBID, index);
   }  

   template <class T, class P> 
   boost::shared_ptr<T> Collection<T,P>::GetItemByDBID(unsigned __int64 DBID, int &foundIndex) const
   {
      CriticalSectionScope scope(_lock);

      foundIndex = 0;

      boost_foreach(boost::shared_ptr<T> item, vecObjects)
      {
         foundIndex++;
         if (item->GetID() == DBID)
         {
            return item;
         }
      }

      foundIndex = 0;
      boost::shared_ptr<T> EmptyObject;
      return EmptyObject;
   }  

   template <class T, class P> 
   bool Collection<T,P>::DeleteItemByDBID(__int64 DBID)
   {
      CriticalSectionScope scope(_lock);

      vector<boost::shared_ptr<T> >::iterator iter = vecObjects.begin();
      vector<boost::shared_ptr<T> >::iterator iterEnd = vecObjects.end();
      
      for (; iter != iterEnd; iter++)
      {
         boost::shared_ptr<T> pObject = (*iter);
         if (pObject->GetID() == DBID)
         {
            P::DeleteObject(pObject);
            vecObjects.erase(iter);
            return true;
         }
      }

      return false;
   }  

   template <class T, class P> 
   bool Collection<T,P>::DeleteAll()
   {
      CriticalSectionScope scope(_lock);

      boost_foreach(boost::shared_ptr<T> object, vecObjects)
      {
         if (!P::DeleteObject(object))
            return false;
      }

      vecObjects.clear();
      return true;
   } 

   template <class T, class P> 
   bool Collection<T,P>::DeleteItem(unsigned int index)
   {
      CriticalSectionScope scope(_lock);

      if (index >= vecObjects.size())
         return false;

      vector<boost::shared_ptr<T> >::iterator iter = vecObjects.begin() + index;
      P::DeleteObject(*iter);
      vecObjects.erase(iter);
      
      return true;
   }  

   template <class T, class P> 
   boost::shared_ptr<T> Collection<T,P>::GetItemByName(const String &sName) const
   {
      CriticalSectionScope scope(_lock);

      vector<boost::shared_ptr<T> >::const_iterator iter = vecObjects.begin();
      
      boost_foreach(boost::shared_ptr<T> pObject, vecObjects)
      {
         if (pObject->GetName().CompareNoCase(sName) == 0)
            return pObject;
      }

      boost::shared_ptr<T> EmptyObject;
      return EmptyObject;
   }  

   template <class T, class P>  
   bool Collection<T,P>::_DBLoad(const String &sSQL)
   {
      return _DBLoad(SQLCommand(sSQL));
   }

   template <class T, class P>  
   bool Collection<T,P>::_DBLoad(const SQLCommand &command)
   {
      CriticalSectionScope scope(_lock);

      vecObjects.clear();

      boost::shared_ptr<DALRecordset> pRS = Application::Instance()->GetDBManager()->OpenRecordset(command);
      if (!pRS)
         return false;

      while (!pRS->IsEOF())
      {
         boost::shared_ptr<T> pItem = boost::shared_ptr<T>(new T);
         if (!P::ReadObject(pItem, pRS))
            return false;

         vecObjects.push_back(pItem);
         pRS->MoveNext();
      }

      return true;
   }

}