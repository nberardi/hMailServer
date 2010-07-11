// Copyright (c) 2010 Martin Knafve / hMailServer.com.  
// http://www.hmailserver.com

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

namespace hMailServer.Administrator
{
   public partial class ucListView : ListView
   {
      private ListViewColumnSorter _columnSorter;

      public delegate void BeforeSelectedIndexChangedHandler();
      public event BeforeSelectedIndexChangedHandler BeforeSelectedIndexChanged;
      List<int> _numericSortOrders = new List<int>();

      public ucListView()
      {
         _columnSorter = new ListViewColumnSorter();

         this.ListViewItemSorter = _columnSorter;

         this.FullRowSelect = true;
      }

      public void SetNumericSortOrder(int index)
      {
         if (!_numericSortOrders.Contains(index))
            _numericSortOrders.Add(index);
      }


      protected override void OnSelectedIndexChanged(EventArgs e)
      {
         base.OnSelectedIndexChanged(e);
      }

      protected override void OnMouseDown(MouseEventArgs e)
      {
         ListViewHitTestInfo info = base.HitTest(new System.Drawing.Point(e.X, e.Y));
         ListViewItem item = info.Item;

         if (item != null)
         {
            int index = item.Index;
            if (this.SelectedIndices.Count == 0)
            {
               if (index != 0)
                  OnBeforeSelectedIndexChanged();
            }
            if (this.SelectedIndices.Count != 0 && index != this.SelectedIndices[0])
            {
               OnBeforeSelectedIndexChanged();
            }
         }

         base.OnMouseDown(e);
      }

      protected override void OnKeyDown(KeyEventArgs e)
      {
         OnBeforeSelectedIndexChanged();

         base.OnKeyDown(e);
      }

      protected virtual void OnBeforeSelectedIndexChanged()
      {
         if (BeforeSelectedIndexChanged != null)
         {
            BeforeSelectedIndexChanged();
         }
      }

      protected override void  OnColumnClick(ColumnClickEventArgs e)
      {
         // Determine if clicked column is already the column that is being sorted.
         if (e.Column == _columnSorter.SortColumn)
         {
            // Reverse the current sort direction for this column.
            if (_columnSorter.Order == SortOrder.Ascending)
            {
               _columnSorter.Order = SortOrder.Descending;
            }
            else
            {
               _columnSorter.Order = SortOrder.Ascending;
            }
         }
         else
         {
            // Set the column number that is to be sorted; default to ascending.
            _columnSorter.SortColumn = e.Column;
            _columnSorter.Order = SortOrder.Ascending;
         }

         if (_numericSortOrders.Contains(e.Column))
            _columnSorter.NumericSort = true;

         // Perform the sort with these new sort options.
         this.Sort();

 	      base.OnColumnClick(e);
      }


   }
}
