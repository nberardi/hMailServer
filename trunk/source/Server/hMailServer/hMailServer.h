

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Dec 08 10:18:23 2011
 */
/* Compiler settings for hMailServer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __hMailServer_h__
#define __hMailServer_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IInterfaceStatus_FWD_DEFINED__
#define __IInterfaceStatus_FWD_DEFINED__
typedef interface IInterfaceStatus IInterfaceStatus;
#endif 	/* __IInterfaceStatus_FWD_DEFINED__ */


#ifndef __IInterfaceSettings_FWD_DEFINED__
#define __IInterfaceSettings_FWD_DEFINED__
typedef interface IInterfaceSettings IInterfaceSettings;
#endif 	/* __IInterfaceSettings_FWD_DEFINED__ */


#ifndef __IInterfaceDomain_FWD_DEFINED__
#define __IInterfaceDomain_FWD_DEFINED__
typedef interface IInterfaceDomain IInterfaceDomain;
#endif 	/* __IInterfaceDomain_FWD_DEFINED__ */


#ifndef __IInterfaceAccounts_FWD_DEFINED__
#define __IInterfaceAccounts_FWD_DEFINED__
typedef interface IInterfaceAccounts IInterfaceAccounts;
#endif 	/* __IInterfaceAccounts_FWD_DEFINED__ */


#ifndef __IInterfaceAccount_FWD_DEFINED__
#define __IInterfaceAccount_FWD_DEFINED__
typedef interface IInterfaceAccount IInterfaceAccount;
#endif 	/* __IInterfaceAccount_FWD_DEFINED__ */


#ifndef __IInterfaceDatabase_FWD_DEFINED__
#define __IInterfaceDatabase_FWD_DEFINED__
typedef interface IInterfaceDatabase IInterfaceDatabase;
#endif 	/* __IInterfaceDatabase_FWD_DEFINED__ */


#ifndef __IInterfaceMessage_FWD_DEFINED__
#define __IInterfaceMessage_FWD_DEFINED__
typedef interface IInterfaceMessage IInterfaceMessage;
#endif 	/* __IInterfaceMessage_FWD_DEFINED__ */


#ifndef __IInterfaceMessages_FWD_DEFINED__
#define __IInterfaceMessages_FWD_DEFINED__
typedef interface IInterfaceMessages IInterfaceMessages;
#endif 	/* __IInterfaceMessages_FWD_DEFINED__ */


#ifndef __IInterfaceAliases_FWD_DEFINED__
#define __IInterfaceAliases_FWD_DEFINED__
typedef interface IInterfaceAliases IInterfaceAliases;
#endif 	/* __IInterfaceAliases_FWD_DEFINED__ */


#ifndef __IInterfaceUtilities_FWD_DEFINED__
#define __IInterfaceUtilities_FWD_DEFINED__
typedef interface IInterfaceUtilities IInterfaceUtilities;
#endif 	/* __IInterfaceUtilities_FWD_DEFINED__ */


#ifndef __IInterfaceAlias_FWD_DEFINED__
#define __IInterfaceAlias_FWD_DEFINED__
typedef interface IInterfaceAlias IInterfaceAlias;
#endif 	/* __IInterfaceAlias_FWD_DEFINED__ */


#ifndef __IInterfaceAttachment_FWD_DEFINED__
#define __IInterfaceAttachment_FWD_DEFINED__
typedef interface IInterfaceAttachment IInterfaceAttachment;
#endif 	/* __IInterfaceAttachment_FWD_DEFINED__ */


#ifndef __IInterfaceAttachments_FWD_DEFINED__
#define __IInterfaceAttachments_FWD_DEFINED__
typedef interface IInterfaceAttachments IInterfaceAttachments;
#endif 	/* __IInterfaceAttachments_FWD_DEFINED__ */


#ifndef __IInterfaceLogging_FWD_DEFINED__
#define __IInterfaceLogging_FWD_DEFINED__
typedef interface IInterfaceLogging IInterfaceLogging;
#endif 	/* __IInterfaceLogging_FWD_DEFINED__ */


#ifndef __IInterfaceDistributionLists_FWD_DEFINED__
#define __IInterfaceDistributionLists_FWD_DEFINED__
typedef interface IInterfaceDistributionLists IInterfaceDistributionLists;
#endif 	/* __IInterfaceDistributionLists_FWD_DEFINED__ */


#ifndef __IInterfaceDistributionList_FWD_DEFINED__
#define __IInterfaceDistributionList_FWD_DEFINED__
typedef interface IInterfaceDistributionList IInterfaceDistributionList;
#endif 	/* __IInterfaceDistributionList_FWD_DEFINED__ */


#ifndef __IInterfaceDistributionListRecipients_FWD_DEFINED__
#define __IInterfaceDistributionListRecipients_FWD_DEFINED__
typedef interface IInterfaceDistributionListRecipients IInterfaceDistributionListRecipients;
#endif 	/* __IInterfaceDistributionListRecipients_FWD_DEFINED__ */


#ifndef __IInterfaceDistributionListRecipient_FWD_DEFINED__
#define __IInterfaceDistributionListRecipient_FWD_DEFINED__
typedef interface IInterfaceDistributionListRecipient IInterfaceDistributionListRecipient;
#endif 	/* __IInterfaceDistributionListRecipient_FWD_DEFINED__ */


#ifndef __IInterfaceSecurityRange_FWD_DEFINED__
#define __IInterfaceSecurityRange_FWD_DEFINED__
typedef interface IInterfaceSecurityRange IInterfaceSecurityRange;
#endif 	/* __IInterfaceSecurityRange_FWD_DEFINED__ */


#ifndef __IInterfaceSecurityRanges_FWD_DEFINED__
#define __IInterfaceSecurityRanges_FWD_DEFINED__
typedef interface IInterfaceSecurityRanges IInterfaceSecurityRanges;
#endif 	/* __IInterfaceSecurityRanges_FWD_DEFINED__ */


#ifndef __IInterfaceAntiVirus_FWD_DEFINED__
#define __IInterfaceAntiVirus_FWD_DEFINED__
typedef interface IInterfaceAntiVirus IInterfaceAntiVirus;
#endif 	/* __IInterfaceAntiVirus_FWD_DEFINED__ */


#ifndef __IInterfaceRoute_FWD_DEFINED__
#define __IInterfaceRoute_FWD_DEFINED__
typedef interface IInterfaceRoute IInterfaceRoute;
#endif 	/* __IInterfaceRoute_FWD_DEFINED__ */


#ifndef __IInterfaceDNSBlackLists_FWD_DEFINED__
#define __IInterfaceDNSBlackLists_FWD_DEFINED__
typedef interface IInterfaceDNSBlackLists IInterfaceDNSBlackLists;
#endif 	/* __IInterfaceDNSBlackLists_FWD_DEFINED__ */


#ifndef __IInterfaceDNSBlackList_FWD_DEFINED__
#define __IInterfaceDNSBlackList_FWD_DEFINED__
typedef interface IInterfaceDNSBlackList IInterfaceDNSBlackList;
#endif 	/* __IInterfaceDNSBlackList_FWD_DEFINED__ */


#ifndef __IInterfaceApplication_FWD_DEFINED__
#define __IInterfaceApplication_FWD_DEFINED__
typedef interface IInterfaceApplication IInterfaceApplication;
#endif 	/* __IInterfaceApplication_FWD_DEFINED__ */


#ifndef __IInterfaceDomains_FWD_DEFINED__
#define __IInterfaceDomains_FWD_DEFINED__
typedef interface IInterfaceDomains IInterfaceDomains;
#endif 	/* __IInterfaceDomains_FWD_DEFINED__ */


#ifndef __IInterfaceRoutes_FWD_DEFINED__
#define __IInterfaceRoutes_FWD_DEFINED__
typedef interface IInterfaceRoutes IInterfaceRoutes;
#endif 	/* __IInterfaceRoutes_FWD_DEFINED__ */


#ifndef __IInterfaceRouteAddress_FWD_DEFINED__
#define __IInterfaceRouteAddress_FWD_DEFINED__
typedef interface IInterfaceRouteAddress IInterfaceRouteAddress;
#endif 	/* __IInterfaceRouteAddress_FWD_DEFINED__ */


#ifndef __IInterfaceRouteAddresses_FWD_DEFINED__
#define __IInterfaceRouteAddresses_FWD_DEFINED__
typedef interface IInterfaceRouteAddresses IInterfaceRouteAddresses;
#endif 	/* __IInterfaceRouteAddresses_FWD_DEFINED__ */


#ifndef __IInterfaceResult_FWD_DEFINED__
#define __IInterfaceResult_FWD_DEFINED__
typedef interface IInterfaceResult IInterfaceResult;
#endif 	/* __IInterfaceResult_FWD_DEFINED__ */


#ifndef __IInterfaceClient_FWD_DEFINED__
#define __IInterfaceClient_FWD_DEFINED__
typedef interface IInterfaceClient IInterfaceClient;
#endif 	/* __IInterfaceClient_FWD_DEFINED__ */


#ifndef __IInterfaceFetchAccount_FWD_DEFINED__
#define __IInterfaceFetchAccount_FWD_DEFINED__
typedef interface IInterfaceFetchAccount IInterfaceFetchAccount;
#endif 	/* __IInterfaceFetchAccount_FWD_DEFINED__ */


#ifndef __IInterfaceFetchAccounts_FWD_DEFINED__
#define __IInterfaceFetchAccounts_FWD_DEFINED__
typedef interface IInterfaceFetchAccounts IInterfaceFetchAccounts;
#endif 	/* __IInterfaceFetchAccounts_FWD_DEFINED__ */


#ifndef __IInterfaceScripting_FWD_DEFINED__
#define __IInterfaceScripting_FWD_DEFINED__
typedef interface IInterfaceScripting IInterfaceScripting;
#endif 	/* __IInterfaceScripting_FWD_DEFINED__ */


#ifndef __IInterfaceDomainAliases_FWD_DEFINED__
#define __IInterfaceDomainAliases_FWD_DEFINED__
typedef interface IInterfaceDomainAliases IInterfaceDomainAliases;
#endif 	/* __IInterfaceDomainAliases_FWD_DEFINED__ */


#ifndef __IInterfaceDomainAlias_FWD_DEFINED__
#define __IInterfaceDomainAlias_FWD_DEFINED__
typedef interface IInterfaceDomainAlias IInterfaceDomainAlias;
#endif 	/* __IInterfaceDomainAlias_FWD_DEFINED__ */


#ifndef __IInterfaceRules_FWD_DEFINED__
#define __IInterfaceRules_FWD_DEFINED__
typedef interface IInterfaceRules IInterfaceRules;
#endif 	/* __IInterfaceRules_FWD_DEFINED__ */


#ifndef __IInterfaceRule_FWD_DEFINED__
#define __IInterfaceRule_FWD_DEFINED__
typedef interface IInterfaceRule IInterfaceRule;
#endif 	/* __IInterfaceRule_FWD_DEFINED__ */


#ifndef __IInterfaceRuleCriteria_FWD_DEFINED__
#define __IInterfaceRuleCriteria_FWD_DEFINED__
typedef interface IInterfaceRuleCriteria IInterfaceRuleCriteria;
#endif 	/* __IInterfaceRuleCriteria_FWD_DEFINED__ */


#ifndef __IInterfaceRuleCriterias_FWD_DEFINED__
#define __IInterfaceRuleCriterias_FWD_DEFINED__
typedef interface IInterfaceRuleCriterias IInterfaceRuleCriterias;
#endif 	/* __IInterfaceRuleCriterias_FWD_DEFINED__ */


#ifndef __IInterfaceRuleAction_FWD_DEFINED__
#define __IInterfaceRuleAction_FWD_DEFINED__
typedef interface IInterfaceRuleAction IInterfaceRuleAction;
#endif 	/* __IInterfaceRuleAction_FWD_DEFINED__ */


#ifndef __IInterfaceRuleActions_FWD_DEFINED__
#define __IInterfaceRuleActions_FWD_DEFINED__
typedef interface IInterfaceRuleActions IInterfaceRuleActions;
#endif 	/* __IInterfaceRuleActions_FWD_DEFINED__ */


#ifndef __IInterfaceRecipients_FWD_DEFINED__
#define __IInterfaceRecipients_FWD_DEFINED__
typedef interface IInterfaceRecipients IInterfaceRecipients;
#endif 	/* __IInterfaceRecipients_FWD_DEFINED__ */


#ifndef __IInterfaceRecipient_FWD_DEFINED__
#define __IInterfaceRecipient_FWD_DEFINED__
typedef interface IInterfaceRecipient IInterfaceRecipient;
#endif 	/* __IInterfaceRecipient_FWD_DEFINED__ */


#ifndef __IInterfaceCache_FWD_DEFINED__
#define __IInterfaceCache_FWD_DEFINED__
typedef interface IInterfaceCache IInterfaceCache;
#endif 	/* __IInterfaceCache_FWD_DEFINED__ */


#ifndef __IInterfaceBackupManager_FWD_DEFINED__
#define __IInterfaceBackupManager_FWD_DEFINED__
typedef interface IInterfaceBackupManager IInterfaceBackupManager;
#endif 	/* __IInterfaceBackupManager_FWD_DEFINED__ */


#ifndef __IInterfaceBackupSettings_FWD_DEFINED__
#define __IInterfaceBackupSettings_FWD_DEFINED__
typedef interface IInterfaceBackupSettings IInterfaceBackupSettings;
#endif 	/* __IInterfaceBackupSettings_FWD_DEFINED__ */


#ifndef __IInterfaceBackup_FWD_DEFINED__
#define __IInterfaceBackup_FWD_DEFINED__
typedef interface IInterfaceBackup IInterfaceBackup;
#endif 	/* __IInterfaceBackup_FWD_DEFINED__ */


#ifndef __IInterfaceGlobalObjects_FWD_DEFINED__
#define __IInterfaceGlobalObjects_FWD_DEFINED__
typedef interface IInterfaceGlobalObjects IInterfaceGlobalObjects;
#endif 	/* __IInterfaceGlobalObjects_FWD_DEFINED__ */


#ifndef __IInterfaceDeliveryQueue_FWD_DEFINED__
#define __IInterfaceDeliveryQueue_FWD_DEFINED__
typedef interface IInterfaceDeliveryQueue IInterfaceDeliveryQueue;
#endif 	/* __IInterfaceDeliveryQueue_FWD_DEFINED__ */


#ifndef __IInterfaceLanguage_FWD_DEFINED__
#define __IInterfaceLanguage_FWD_DEFINED__
typedef interface IInterfaceLanguage IInterfaceLanguage;
#endif 	/* __IInterfaceLanguage_FWD_DEFINED__ */


#ifndef __IInterfaceIMAPFolder_FWD_DEFINED__
#define __IInterfaceIMAPFolder_FWD_DEFINED__
typedef interface IInterfaceIMAPFolder IInterfaceIMAPFolder;
#endif 	/* __IInterfaceIMAPFolder_FWD_DEFINED__ */


#ifndef __IInterfaceIMAPFolders_FWD_DEFINED__
#define __IInterfaceIMAPFolders_FWD_DEFINED__
typedef interface IInterfaceIMAPFolders IInterfaceIMAPFolders;
#endif 	/* __IInterfaceIMAPFolders_FWD_DEFINED__ */


#ifndef __IInterfaceEventLog_FWD_DEFINED__
#define __IInterfaceEventLog_FWD_DEFINED__
typedef interface IInterfaceEventLog IInterfaceEventLog;
#endif 	/* __IInterfaceEventLog_FWD_DEFINED__ */


#ifndef __IInterfaceSURBLServers_FWD_DEFINED__
#define __IInterfaceSURBLServers_FWD_DEFINED__
typedef interface IInterfaceSURBLServers IInterfaceSURBLServers;
#endif 	/* __IInterfaceSURBLServers_FWD_DEFINED__ */


#ifndef __IInterfaceSURBLServer_FWD_DEFINED__
#define __IInterfaceSURBLServer_FWD_DEFINED__
typedef interface IInterfaceSURBLServer IInterfaceSURBLServer;
#endif 	/* __IInterfaceSURBLServer_FWD_DEFINED__ */


#ifndef __IInterfaceAntiSpam_FWD_DEFINED__
#define __IInterfaceAntiSpam_FWD_DEFINED__
typedef interface IInterfaceAntiSpam IInterfaceAntiSpam;
#endif 	/* __IInterfaceAntiSpam_FWD_DEFINED__ */


#ifndef __IInterfaceBlockedAttachment_FWD_DEFINED__
#define __IInterfaceBlockedAttachment_FWD_DEFINED__
typedef interface IInterfaceBlockedAttachment IInterfaceBlockedAttachment;
#endif 	/* __IInterfaceBlockedAttachment_FWD_DEFINED__ */


#ifndef __IInterfaceBlockedAttachments_FWD_DEFINED__
#define __IInterfaceBlockedAttachments_FWD_DEFINED__
typedef interface IInterfaceBlockedAttachments IInterfaceBlockedAttachments;
#endif 	/* __IInterfaceBlockedAttachments_FWD_DEFINED__ */


#ifndef __IInterfaceServerMessages_FWD_DEFINED__
#define __IInterfaceServerMessages_FWD_DEFINED__
typedef interface IInterfaceServerMessages IInterfaceServerMessages;
#endif 	/* __IInterfaceServerMessages_FWD_DEFINED__ */


#ifndef __IInterfaceServerMessage_FWD_DEFINED__
#define __IInterfaceServerMessage_FWD_DEFINED__
typedef interface IInterfaceServerMessage IInterfaceServerMessage;
#endif 	/* __IInterfaceServerMessage_FWD_DEFINED__ */


#ifndef __IInterfaceGreyListingWhiteAddresses_FWD_DEFINED__
#define __IInterfaceGreyListingWhiteAddresses_FWD_DEFINED__
typedef interface IInterfaceGreyListingWhiteAddresses IInterfaceGreyListingWhiteAddresses;
#endif 	/* __IInterfaceGreyListingWhiteAddresses_FWD_DEFINED__ */


#ifndef __IInterfaceGreyListingWhiteAddress_FWD_DEFINED__
#define __IInterfaceGreyListingWhiteAddress_FWD_DEFINED__
typedef interface IInterfaceGreyListingWhiteAddress IInterfaceGreyListingWhiteAddress;
#endif 	/* __IInterfaceGreyListingWhiteAddress_FWD_DEFINED__ */


#ifndef __IInterfaceTCPIPPorts_FWD_DEFINED__
#define __IInterfaceTCPIPPorts_FWD_DEFINED__
typedef interface IInterfaceTCPIPPorts IInterfaceTCPIPPorts;
#endif 	/* __IInterfaceTCPIPPorts_FWD_DEFINED__ */


#ifndef __IInterfaceTCPIPPort_FWD_DEFINED__
#define __IInterfaceTCPIPPort_FWD_DEFINED__
typedef interface IInterfaceTCPIPPort IInterfaceTCPIPPort;
#endif 	/* __IInterfaceTCPIPPort_FWD_DEFINED__ */


#ifndef __IInterfaceWhiteListAddresses_FWD_DEFINED__
#define __IInterfaceWhiteListAddresses_FWD_DEFINED__
typedef interface IInterfaceWhiteListAddresses IInterfaceWhiteListAddresses;
#endif 	/* __IInterfaceWhiteListAddresses_FWD_DEFINED__ */


#ifndef __IInterfaceWhiteListAddress_FWD_DEFINED__
#define __IInterfaceWhiteListAddress_FWD_DEFINED__
typedef interface IInterfaceWhiteListAddress IInterfaceWhiteListAddress;
#endif 	/* __IInterfaceWhiteListAddress_FWD_DEFINED__ */


#ifndef __IInterfaceMessageHeader_FWD_DEFINED__
#define __IInterfaceMessageHeader_FWD_DEFINED__
typedef interface IInterfaceMessageHeader IInterfaceMessageHeader;
#endif 	/* __IInterfaceMessageHeader_FWD_DEFINED__ */


#ifndef __IInterfaceMessageHeaders_FWD_DEFINED__
#define __IInterfaceMessageHeaders_FWD_DEFINED__
typedef interface IInterfaceMessageHeaders IInterfaceMessageHeaders;
#endif 	/* __IInterfaceMessageHeaders_FWD_DEFINED__ */


#ifndef __IInterfaceSSLCertificate_FWD_DEFINED__
#define __IInterfaceSSLCertificate_FWD_DEFINED__
typedef interface IInterfaceSSLCertificate IInterfaceSSLCertificate;
#endif 	/* __IInterfaceSSLCertificate_FWD_DEFINED__ */


#ifndef __IInterfaceSSLCertificates_FWD_DEFINED__
#define __IInterfaceSSLCertificates_FWD_DEFINED__
typedef interface IInterfaceSSLCertificates IInterfaceSSLCertificates;
#endif 	/* __IInterfaceSSLCertificates_FWD_DEFINED__ */


#ifndef __IInterfaceGroups_FWD_DEFINED__
#define __IInterfaceGroups_FWD_DEFINED__
typedef interface IInterfaceGroups IInterfaceGroups;
#endif 	/* __IInterfaceGroups_FWD_DEFINED__ */


#ifndef __IInterfaceGroup_FWD_DEFINED__
#define __IInterfaceGroup_FWD_DEFINED__
typedef interface IInterfaceGroup IInterfaceGroup;
#endif 	/* __IInterfaceGroup_FWD_DEFINED__ */


#ifndef __IInterfaceGroupMembers_FWD_DEFINED__
#define __IInterfaceGroupMembers_FWD_DEFINED__
typedef interface IInterfaceGroupMembers IInterfaceGroupMembers;
#endif 	/* __IInterfaceGroupMembers_FWD_DEFINED__ */


#ifndef __IInterfaceGroupMember_FWD_DEFINED__
#define __IInterfaceGroupMember_FWD_DEFINED__
typedef interface IInterfaceGroupMember IInterfaceGroupMember;
#endif 	/* __IInterfaceGroupMember_FWD_DEFINED__ */


#ifndef __IInterfaceIMAPFolderPermission_FWD_DEFINED__
#define __IInterfaceIMAPFolderPermission_FWD_DEFINED__
typedef interface IInterfaceIMAPFolderPermission IInterfaceIMAPFolderPermission;
#endif 	/* __IInterfaceIMAPFolderPermission_FWD_DEFINED__ */


#ifndef __IInterfaceIMAPFolderPermissions_FWD_DEFINED__
#define __IInterfaceIMAPFolderPermissions_FWD_DEFINED__
typedef interface IInterfaceIMAPFolderPermissions IInterfaceIMAPFolderPermissions;
#endif 	/* __IInterfaceIMAPFolderPermissions_FWD_DEFINED__ */


#ifndef __IInterfaceDirectories_FWD_DEFINED__
#define __IInterfaceDirectories_FWD_DEFINED__
typedef interface IInterfaceDirectories IInterfaceDirectories;
#endif 	/* __IInterfaceDirectories_FWD_DEFINED__ */


#ifndef __IInterfaceLanguages_FWD_DEFINED__
#define __IInterfaceLanguages_FWD_DEFINED__
typedef interface IInterfaceLanguages IInterfaceLanguages;
#endif 	/* __IInterfaceLanguages_FWD_DEFINED__ */


#ifndef __IInterfaceLinks_FWD_DEFINED__
#define __IInterfaceLinks_FWD_DEFINED__
typedef interface IInterfaceLinks IInterfaceLinks;
#endif 	/* __IInterfaceLinks_FWD_DEFINED__ */


#ifndef __IInterfaceIncomingRelay_FWD_DEFINED__
#define __IInterfaceIncomingRelay_FWD_DEFINED__
typedef interface IInterfaceIncomingRelay IInterfaceIncomingRelay;
#endif 	/* __IInterfaceIncomingRelay_FWD_DEFINED__ */


#ifndef __IInterfaceIncomingRelays_FWD_DEFINED__
#define __IInterfaceIncomingRelays_FWD_DEFINED__
typedef interface IInterfaceIncomingRelays IInterfaceIncomingRelays;
#endif 	/* __IInterfaceIncomingRelays_FWD_DEFINED__ */


#ifndef __IInterfaceMessageIndexing_FWD_DEFINED__
#define __IInterfaceMessageIndexing_FWD_DEFINED__
typedef interface IInterfaceMessageIndexing IInterfaceMessageIndexing;
#endif 	/* __IInterfaceMessageIndexing_FWD_DEFINED__ */


#ifndef __IInterfaceDiagnostics_FWD_DEFINED__
#define __IInterfaceDiagnostics_FWD_DEFINED__
typedef interface IInterfaceDiagnostics IInterfaceDiagnostics;
#endif 	/* __IInterfaceDiagnostics_FWD_DEFINED__ */


#ifndef __IInterfaceDiagnosticResults_FWD_DEFINED__
#define __IInterfaceDiagnosticResults_FWD_DEFINED__
typedef interface IInterfaceDiagnosticResults IInterfaceDiagnosticResults;
#endif 	/* __IInterfaceDiagnosticResults_FWD_DEFINED__ */


#ifndef __IInterfaceDiagnosticResult_FWD_DEFINED__
#define __IInterfaceDiagnosticResult_FWD_DEFINED__
typedef interface IInterfaceDiagnosticResult IInterfaceDiagnosticResult;
#endif 	/* __IInterfaceDiagnosticResult_FWD_DEFINED__ */


#ifndef __DiagnosticResults_FWD_DEFINED__
#define __DiagnosticResults_FWD_DEFINED__

#ifdef __cplusplus
typedef class DiagnosticResults DiagnosticResults;
#else
typedef struct DiagnosticResults DiagnosticResults;
#endif /* __cplusplus */

#endif 	/* __DiagnosticResults_FWD_DEFINED__ */


#ifndef __DiagnosticResult_FWD_DEFINED__
#define __DiagnosticResult_FWD_DEFINED__

#ifdef __cplusplus
typedef class DiagnosticResult DiagnosticResult;
#else
typedef struct DiagnosticResult DiagnosticResult;
#endif /* __cplusplus */

#endif 	/* __DiagnosticResult_FWD_DEFINED__ */


#ifndef __Diagnostics_FWD_DEFINED__
#define __Diagnostics_FWD_DEFINED__

#ifdef __cplusplus
typedef class Diagnostics Diagnostics;
#else
typedef struct Diagnostics Diagnostics;
#endif /* __cplusplus */

#endif 	/* __Diagnostics_FWD_DEFINED__ */


#ifndef __Status_FWD_DEFINED__
#define __Status_FWD_DEFINED__

#ifdef __cplusplus
typedef class Status Status;
#else
typedef struct Status Status;
#endif /* __cplusplus */

#endif 	/* __Status_FWD_DEFINED__ */


#ifndef __Settings_FWD_DEFINED__
#define __Settings_FWD_DEFINED__

#ifdef __cplusplus
typedef class Settings Settings;
#else
typedef struct Settings Settings;
#endif /* __cplusplus */

#endif 	/* __Settings_FWD_DEFINED__ */


#ifndef __Domain_FWD_DEFINED__
#define __Domain_FWD_DEFINED__

#ifdef __cplusplus
typedef class Domain Domain;
#else
typedef struct Domain Domain;
#endif /* __cplusplus */

#endif 	/* __Domain_FWD_DEFINED__ */


#ifndef __Accounts_FWD_DEFINED__
#define __Accounts_FWD_DEFINED__

#ifdef __cplusplus
typedef class Accounts Accounts;
#else
typedef struct Accounts Accounts;
#endif /* __cplusplus */

#endif 	/* __Accounts_FWD_DEFINED__ */


#ifndef __Account_FWD_DEFINED__
#define __Account_FWD_DEFINED__

#ifdef __cplusplus
typedef class Account Account;
#else
typedef struct Account Account;
#endif /* __cplusplus */

#endif 	/* __Account_FWD_DEFINED__ */


#ifndef __Database_FWD_DEFINED__
#define __Database_FWD_DEFINED__

#ifdef __cplusplus
typedef class Database Database;
#else
typedef struct Database Database;
#endif /* __cplusplus */

#endif 	/* __Database_FWD_DEFINED__ */


#ifndef __Message_FWD_DEFINED__
#define __Message_FWD_DEFINED__

#ifdef __cplusplus
typedef class Message Message;
#else
typedef struct Message Message;
#endif /* __cplusplus */

#endif 	/* __Message_FWD_DEFINED__ */


#ifndef __Messages_FWD_DEFINED__
#define __Messages_FWD_DEFINED__

#ifdef __cplusplus
typedef class Messages Messages;
#else
typedef struct Messages Messages;
#endif /* __cplusplus */

#endif 	/* __Messages_FWD_DEFINED__ */


#ifndef __Aliases_FWD_DEFINED__
#define __Aliases_FWD_DEFINED__

#ifdef __cplusplus
typedef class Aliases Aliases;
#else
typedef struct Aliases Aliases;
#endif /* __cplusplus */

#endif 	/* __Aliases_FWD_DEFINED__ */


#ifndef __Utilities_FWD_DEFINED__
#define __Utilities_FWD_DEFINED__

#ifdef __cplusplus
typedef class Utilities Utilities;
#else
typedef struct Utilities Utilities;
#endif /* __cplusplus */

#endif 	/* __Utilities_FWD_DEFINED__ */


#ifndef __Alias_FWD_DEFINED__
#define __Alias_FWD_DEFINED__

#ifdef __cplusplus
typedef class Alias Alias;
#else
typedef struct Alias Alias;
#endif /* __cplusplus */

#endif 	/* __Alias_FWD_DEFINED__ */


#ifndef __Attachment_FWD_DEFINED__
#define __Attachment_FWD_DEFINED__

#ifdef __cplusplus
typedef class Attachment Attachment;
#else
typedef struct Attachment Attachment;
#endif /* __cplusplus */

#endif 	/* __Attachment_FWD_DEFINED__ */


#ifndef __Attachments_FWD_DEFINED__
#define __Attachments_FWD_DEFINED__

#ifdef __cplusplus
typedef class Attachments Attachments;
#else
typedef struct Attachments Attachments;
#endif /* __cplusplus */

#endif 	/* __Attachments_FWD_DEFINED__ */


#ifndef __Logging_FWD_DEFINED__
#define __Logging_FWD_DEFINED__

#ifdef __cplusplus
typedef class Logging Logging;
#else
typedef struct Logging Logging;
#endif /* __cplusplus */

#endif 	/* __Logging_FWD_DEFINED__ */


#ifndef __DistributionLists_FWD_DEFINED__
#define __DistributionLists_FWD_DEFINED__

#ifdef __cplusplus
typedef class DistributionLists DistributionLists;
#else
typedef struct DistributionLists DistributionLists;
#endif /* __cplusplus */

#endif 	/* __DistributionLists_FWD_DEFINED__ */


#ifndef __DistributionList_FWD_DEFINED__
#define __DistributionList_FWD_DEFINED__

#ifdef __cplusplus
typedef class DistributionList DistributionList;
#else
typedef struct DistributionList DistributionList;
#endif /* __cplusplus */

#endif 	/* __DistributionList_FWD_DEFINED__ */


#ifndef __DistributionListRecipients_FWD_DEFINED__
#define __DistributionListRecipients_FWD_DEFINED__

#ifdef __cplusplus
typedef class DistributionListRecipients DistributionListRecipients;
#else
typedef struct DistributionListRecipients DistributionListRecipients;
#endif /* __cplusplus */

#endif 	/* __DistributionListRecipients_FWD_DEFINED__ */


#ifndef __DistributionListRecipient_FWD_DEFINED__
#define __DistributionListRecipient_FWD_DEFINED__

#ifdef __cplusplus
typedef class DistributionListRecipient DistributionListRecipient;
#else
typedef struct DistributionListRecipient DistributionListRecipient;
#endif /* __cplusplus */

#endif 	/* __DistributionListRecipient_FWD_DEFINED__ */


#ifndef __SecurityRange_FWD_DEFINED__
#define __SecurityRange_FWD_DEFINED__

#ifdef __cplusplus
typedef class SecurityRange SecurityRange;
#else
typedef struct SecurityRange SecurityRange;
#endif /* __cplusplus */

#endif 	/* __SecurityRange_FWD_DEFINED__ */


#ifndef __SecurityRanges_FWD_DEFINED__
#define __SecurityRanges_FWD_DEFINED__

#ifdef __cplusplus
typedef class SecurityRanges SecurityRanges;
#else
typedef struct SecurityRanges SecurityRanges;
#endif /* __cplusplus */

#endif 	/* __SecurityRanges_FWD_DEFINED__ */


#ifndef __AntiVirus_FWD_DEFINED__
#define __AntiVirus_FWD_DEFINED__

#ifdef __cplusplus
typedef class AntiVirus AntiVirus;
#else
typedef struct AntiVirus AntiVirus;
#endif /* __cplusplus */

#endif 	/* __AntiVirus_FWD_DEFINED__ */


#ifndef __Route_FWD_DEFINED__
#define __Route_FWD_DEFINED__

#ifdef __cplusplus
typedef class Route Route;
#else
typedef struct Route Route;
#endif /* __cplusplus */

#endif 	/* __Route_FWD_DEFINED__ */


#ifndef __DNSBlackLists_FWD_DEFINED__
#define __DNSBlackLists_FWD_DEFINED__

#ifdef __cplusplus
typedef class DNSBlackLists DNSBlackLists;
#else
typedef struct DNSBlackLists DNSBlackLists;
#endif /* __cplusplus */

#endif 	/* __DNSBlackLists_FWD_DEFINED__ */


#ifndef __DNSBlackList_FWD_DEFINED__
#define __DNSBlackList_FWD_DEFINED__

#ifdef __cplusplus
typedef class DNSBlackList DNSBlackList;
#else
typedef struct DNSBlackList DNSBlackList;
#endif /* __cplusplus */

#endif 	/* __DNSBlackList_FWD_DEFINED__ */


#ifndef __Application_FWD_DEFINED__
#define __Application_FWD_DEFINED__

#ifdef __cplusplus
typedef class Application Application;
#else
typedef struct Application Application;
#endif /* __cplusplus */

#endif 	/* __Application_FWD_DEFINED__ */


#ifndef __Domains_FWD_DEFINED__
#define __Domains_FWD_DEFINED__

#ifdef __cplusplus
typedef class Domains Domains;
#else
typedef struct Domains Domains;
#endif /* __cplusplus */

#endif 	/* __Domains_FWD_DEFINED__ */


#ifndef __Routes_FWD_DEFINED__
#define __Routes_FWD_DEFINED__

#ifdef __cplusplus
typedef class Routes Routes;
#else
typedef struct Routes Routes;
#endif /* __cplusplus */

#endif 	/* __Routes_FWD_DEFINED__ */


#ifndef __RouteAddress_FWD_DEFINED__
#define __RouteAddress_FWD_DEFINED__

#ifdef __cplusplus
typedef class RouteAddress RouteAddress;
#else
typedef struct RouteAddress RouteAddress;
#endif /* __cplusplus */

#endif 	/* __RouteAddress_FWD_DEFINED__ */


#ifndef __RouteAddresses_FWD_DEFINED__
#define __RouteAddresses_FWD_DEFINED__

#ifdef __cplusplus
typedef class RouteAddresses RouteAddresses;
#else
typedef struct RouteAddresses RouteAddresses;
#endif /* __cplusplus */

#endif 	/* __RouteAddresses_FWD_DEFINED__ */


#ifndef __Result_FWD_DEFINED__
#define __Result_FWD_DEFINED__

#ifdef __cplusplus
typedef class Result Result;
#else
typedef struct Result Result;
#endif /* __cplusplus */

#endif 	/* __Result_FWD_DEFINED__ */


#ifndef __Client_FWD_DEFINED__
#define __Client_FWD_DEFINED__

#ifdef __cplusplus
typedef class Client Client;
#else
typedef struct Client Client;
#endif /* __cplusplus */

#endif 	/* __Client_FWD_DEFINED__ */


#ifndef __FetchAccount_FWD_DEFINED__
#define __FetchAccount_FWD_DEFINED__

#ifdef __cplusplus
typedef class FetchAccount FetchAccount;
#else
typedef struct FetchAccount FetchAccount;
#endif /* __cplusplus */

#endif 	/* __FetchAccount_FWD_DEFINED__ */


#ifndef __FetchAccounts_FWD_DEFINED__
#define __FetchAccounts_FWD_DEFINED__

#ifdef __cplusplus
typedef class FetchAccounts FetchAccounts;
#else
typedef struct FetchAccounts FetchAccounts;
#endif /* __cplusplus */

#endif 	/* __FetchAccounts_FWD_DEFINED__ */


#ifndef __Scripting_FWD_DEFINED__
#define __Scripting_FWD_DEFINED__

#ifdef __cplusplus
typedef class Scripting Scripting;
#else
typedef struct Scripting Scripting;
#endif /* __cplusplus */

#endif 	/* __Scripting_FWD_DEFINED__ */


#ifndef __DomainAliases_FWD_DEFINED__
#define __DomainAliases_FWD_DEFINED__

#ifdef __cplusplus
typedef class DomainAliases DomainAliases;
#else
typedef struct DomainAliases DomainAliases;
#endif /* __cplusplus */

#endif 	/* __DomainAliases_FWD_DEFINED__ */


#ifndef __DomainAlias_FWD_DEFINED__
#define __DomainAlias_FWD_DEFINED__

#ifdef __cplusplus
typedef class DomainAlias DomainAlias;
#else
typedef struct DomainAlias DomainAlias;
#endif /* __cplusplus */

#endif 	/* __DomainAlias_FWD_DEFINED__ */


#ifndef __Rules_FWD_DEFINED__
#define __Rules_FWD_DEFINED__

#ifdef __cplusplus
typedef class Rules Rules;
#else
typedef struct Rules Rules;
#endif /* __cplusplus */

#endif 	/* __Rules_FWD_DEFINED__ */


#ifndef __Rule_FWD_DEFINED__
#define __Rule_FWD_DEFINED__

#ifdef __cplusplus
typedef class Rule Rule;
#else
typedef struct Rule Rule;
#endif /* __cplusplus */

#endif 	/* __Rule_FWD_DEFINED__ */


#ifndef __RuleCriteria_FWD_DEFINED__
#define __RuleCriteria_FWD_DEFINED__

#ifdef __cplusplus
typedef class RuleCriteria RuleCriteria;
#else
typedef struct RuleCriteria RuleCriteria;
#endif /* __cplusplus */

#endif 	/* __RuleCriteria_FWD_DEFINED__ */


#ifndef __RuleCriterias_FWD_DEFINED__
#define __RuleCriterias_FWD_DEFINED__

#ifdef __cplusplus
typedef class RuleCriterias RuleCriterias;
#else
typedef struct RuleCriterias RuleCriterias;
#endif /* __cplusplus */

#endif 	/* __RuleCriterias_FWD_DEFINED__ */


#ifndef __RuleAction_FWD_DEFINED__
#define __RuleAction_FWD_DEFINED__

#ifdef __cplusplus
typedef class RuleAction RuleAction;
#else
typedef struct RuleAction RuleAction;
#endif /* __cplusplus */

#endif 	/* __RuleAction_FWD_DEFINED__ */


#ifndef __RuleActions_FWD_DEFINED__
#define __RuleActions_FWD_DEFINED__

#ifdef __cplusplus
typedef class RuleActions RuleActions;
#else
typedef struct RuleActions RuleActions;
#endif /* __cplusplus */

#endif 	/* __RuleActions_FWD_DEFINED__ */


#ifndef __Recipients_FWD_DEFINED__
#define __Recipients_FWD_DEFINED__

#ifdef __cplusplus
typedef class Recipients Recipients;
#else
typedef struct Recipients Recipients;
#endif /* __cplusplus */

#endif 	/* __Recipients_FWD_DEFINED__ */


#ifndef __Recipient_FWD_DEFINED__
#define __Recipient_FWD_DEFINED__

#ifdef __cplusplus
typedef class Recipient Recipient;
#else
typedef struct Recipient Recipient;
#endif /* __cplusplus */

#endif 	/* __Recipient_FWD_DEFINED__ */


#ifndef __Cache_FWD_DEFINED__
#define __Cache_FWD_DEFINED__

#ifdef __cplusplus
typedef class Cache Cache;
#else
typedef struct Cache Cache;
#endif /* __cplusplus */

#endif 	/* __Cache_FWD_DEFINED__ */


#ifndef __BackupManager_FWD_DEFINED__
#define __BackupManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class BackupManager BackupManager;
#else
typedef struct BackupManager BackupManager;
#endif /* __cplusplus */

#endif 	/* __BackupManager_FWD_DEFINED__ */


#ifndef __BackupSettings_FWD_DEFINED__
#define __BackupSettings_FWD_DEFINED__

#ifdef __cplusplus
typedef class BackupSettings BackupSettings;
#else
typedef struct BackupSettings BackupSettings;
#endif /* __cplusplus */

#endif 	/* __BackupSettings_FWD_DEFINED__ */


#ifndef __Backup_FWD_DEFINED__
#define __Backup_FWD_DEFINED__

#ifdef __cplusplus
typedef class Backup Backup;
#else
typedef struct Backup Backup;
#endif /* __cplusplus */

#endif 	/* __Backup_FWD_DEFINED__ */


#ifndef __GlobalObjects_FWD_DEFINED__
#define __GlobalObjects_FWD_DEFINED__

#ifdef __cplusplus
typedef class GlobalObjects GlobalObjects;
#else
typedef struct GlobalObjects GlobalObjects;
#endif /* __cplusplus */

#endif 	/* __GlobalObjects_FWD_DEFINED__ */


#ifndef __DeliveryQueue_FWD_DEFINED__
#define __DeliveryQueue_FWD_DEFINED__

#ifdef __cplusplus
typedef class DeliveryQueue DeliveryQueue;
#else
typedef struct DeliveryQueue DeliveryQueue;
#endif /* __cplusplus */

#endif 	/* __DeliveryQueue_FWD_DEFINED__ */


#ifndef __Language_FWD_DEFINED__
#define __Language_FWD_DEFINED__

#ifdef __cplusplus
typedef class Language Language;
#else
typedef struct Language Language;
#endif /* __cplusplus */

#endif 	/* __Language_FWD_DEFINED__ */


#ifndef __IMAPFolder_FWD_DEFINED__
#define __IMAPFolder_FWD_DEFINED__

#ifdef __cplusplus
typedef class IMAPFolder IMAPFolder;
#else
typedef struct IMAPFolder IMAPFolder;
#endif /* __cplusplus */

#endif 	/* __IMAPFolder_FWD_DEFINED__ */


#ifndef __IMAPFolders_FWD_DEFINED__
#define __IMAPFolders_FWD_DEFINED__

#ifdef __cplusplus
typedef class IMAPFolders IMAPFolders;
#else
typedef struct IMAPFolders IMAPFolders;
#endif /* __cplusplus */

#endif 	/* __IMAPFolders_FWD_DEFINED__ */


#ifndef __EventLog_FWD_DEFINED__
#define __EventLog_FWD_DEFINED__

#ifdef __cplusplus
typedef class EventLog EventLog;
#else
typedef struct EventLog EventLog;
#endif /* __cplusplus */

#endif 	/* __EventLog_FWD_DEFINED__ */


#ifndef __SURBLServers_FWD_DEFINED__
#define __SURBLServers_FWD_DEFINED__

#ifdef __cplusplus
typedef class SURBLServers SURBLServers;
#else
typedef struct SURBLServers SURBLServers;
#endif /* __cplusplus */

#endif 	/* __SURBLServers_FWD_DEFINED__ */


#ifndef __SURBLServer_FWD_DEFINED__
#define __SURBLServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class SURBLServer SURBLServer;
#else
typedef struct SURBLServer SURBLServer;
#endif /* __cplusplus */

#endif 	/* __SURBLServer_FWD_DEFINED__ */


#ifndef __AntiSpam_FWD_DEFINED__
#define __AntiSpam_FWD_DEFINED__

#ifdef __cplusplus
typedef class AntiSpam AntiSpam;
#else
typedef struct AntiSpam AntiSpam;
#endif /* __cplusplus */

#endif 	/* __AntiSpam_FWD_DEFINED__ */


#ifndef __BlockedAttachment_FWD_DEFINED__
#define __BlockedAttachment_FWD_DEFINED__

#ifdef __cplusplus
typedef class BlockedAttachment BlockedAttachment;
#else
typedef struct BlockedAttachment BlockedAttachment;
#endif /* __cplusplus */

#endif 	/* __BlockedAttachment_FWD_DEFINED__ */


#ifndef __BlockedAttachments_FWD_DEFINED__
#define __BlockedAttachments_FWD_DEFINED__

#ifdef __cplusplus
typedef class BlockedAttachments BlockedAttachments;
#else
typedef struct BlockedAttachments BlockedAttachments;
#endif /* __cplusplus */

#endif 	/* __BlockedAttachments_FWD_DEFINED__ */


#ifndef __ServerMessages_FWD_DEFINED__
#define __ServerMessages_FWD_DEFINED__

#ifdef __cplusplus
typedef class ServerMessages ServerMessages;
#else
typedef struct ServerMessages ServerMessages;
#endif /* __cplusplus */

#endif 	/* __ServerMessages_FWD_DEFINED__ */


#ifndef __ServerMessage_FWD_DEFINED__
#define __ServerMessage_FWD_DEFINED__

#ifdef __cplusplus
typedef class ServerMessage ServerMessage;
#else
typedef struct ServerMessage ServerMessage;
#endif /* __cplusplus */

#endif 	/* __ServerMessage_FWD_DEFINED__ */


#ifndef __TCPIPPort_FWD_DEFINED__
#define __TCPIPPort_FWD_DEFINED__

#ifdef __cplusplus
typedef class TCPIPPort TCPIPPort;
#else
typedef struct TCPIPPort TCPIPPort;
#endif /* __cplusplus */

#endif 	/* __TCPIPPort_FWD_DEFINED__ */


#ifndef __TCPIPPorts_FWD_DEFINED__
#define __TCPIPPorts_FWD_DEFINED__

#ifdef __cplusplus
typedef class TCPIPPorts TCPIPPorts;
#else
typedef struct TCPIPPorts TCPIPPorts;
#endif /* __cplusplus */

#endif 	/* __TCPIPPorts_FWD_DEFINED__ */


#ifndef __GreyListingWhiteAddress_FWD_DEFINED__
#define __GreyListingWhiteAddress_FWD_DEFINED__

#ifdef __cplusplus
typedef class GreyListingWhiteAddress GreyListingWhiteAddress;
#else
typedef struct GreyListingWhiteAddress GreyListingWhiteAddress;
#endif /* __cplusplus */

#endif 	/* __GreyListingWhiteAddress_FWD_DEFINED__ */


#ifndef __GreyListingWhiteAddresses_FWD_DEFINED__
#define __GreyListingWhiteAddresses_FWD_DEFINED__

#ifdef __cplusplus
typedef class GreyListingWhiteAddresses GreyListingWhiteAddresses;
#else
typedef struct GreyListingWhiteAddresses GreyListingWhiteAddresses;
#endif /* __cplusplus */

#endif 	/* __GreyListingWhiteAddresses_FWD_DEFINED__ */


#ifndef __WhiteListAddresses_FWD_DEFINED__
#define __WhiteListAddresses_FWD_DEFINED__

#ifdef __cplusplus
typedef class WhiteListAddresses WhiteListAddresses;
#else
typedef struct WhiteListAddresses WhiteListAddresses;
#endif /* __cplusplus */

#endif 	/* __WhiteListAddresses_FWD_DEFINED__ */


#ifndef __WhiteListAddress_FWD_DEFINED__
#define __WhiteListAddress_FWD_DEFINED__

#ifdef __cplusplus
typedef class WhiteListAddress WhiteListAddress;
#else
typedef struct WhiteListAddress WhiteListAddress;
#endif /* __cplusplus */

#endif 	/* __WhiteListAddress_FWD_DEFINED__ */


#ifndef __MessageHeader_FWD_DEFINED__
#define __MessageHeader_FWD_DEFINED__

#ifdef __cplusplus
typedef class MessageHeader MessageHeader;
#else
typedef struct MessageHeader MessageHeader;
#endif /* __cplusplus */

#endif 	/* __MessageHeader_FWD_DEFINED__ */


#ifndef __MessageHeaders_FWD_DEFINED__
#define __MessageHeaders_FWD_DEFINED__

#ifdef __cplusplus
typedef class MessageHeaders MessageHeaders;
#else
typedef struct MessageHeaders MessageHeaders;
#endif /* __cplusplus */

#endif 	/* __MessageHeaders_FWD_DEFINED__ */


#ifndef __SSLCertificate_FWD_DEFINED__
#define __SSLCertificate_FWD_DEFINED__

#ifdef __cplusplus
typedef class SSLCertificate SSLCertificate;
#else
typedef struct SSLCertificate SSLCertificate;
#endif /* __cplusplus */

#endif 	/* __SSLCertificate_FWD_DEFINED__ */


#ifndef __SSLCertificates_FWD_DEFINED__
#define __SSLCertificates_FWD_DEFINED__

#ifdef __cplusplus
typedef class SSLCertificates SSLCertificates;
#else
typedef struct SSLCertificates SSLCertificates;
#endif /* __cplusplus */

#endif 	/* __SSLCertificates_FWD_DEFINED__ */


#ifndef __Groups_FWD_DEFINED__
#define __Groups_FWD_DEFINED__

#ifdef __cplusplus
typedef class Groups Groups;
#else
typedef struct Groups Groups;
#endif /* __cplusplus */

#endif 	/* __Groups_FWD_DEFINED__ */


#ifndef __Group_FWD_DEFINED__
#define __Group_FWD_DEFINED__

#ifdef __cplusplus
typedef class Group Group;
#else
typedef struct Group Group;
#endif /* __cplusplus */

#endif 	/* __Group_FWD_DEFINED__ */


#ifndef __GroupMembers_FWD_DEFINED__
#define __GroupMembers_FWD_DEFINED__

#ifdef __cplusplus
typedef class GroupMembers GroupMembers;
#else
typedef struct GroupMembers GroupMembers;
#endif /* __cplusplus */

#endif 	/* __GroupMembers_FWD_DEFINED__ */


#ifndef __GroupMember_FWD_DEFINED__
#define __GroupMember_FWD_DEFINED__

#ifdef __cplusplus
typedef class GroupMember GroupMember;
#else
typedef struct GroupMember GroupMember;
#endif /* __cplusplus */

#endif 	/* __GroupMember_FWD_DEFINED__ */


#ifndef __IMAPFolderPermission_FWD_DEFINED__
#define __IMAPFolderPermission_FWD_DEFINED__

#ifdef __cplusplus
typedef class IMAPFolderPermission IMAPFolderPermission;
#else
typedef struct IMAPFolderPermission IMAPFolderPermission;
#endif /* __cplusplus */

#endif 	/* __IMAPFolderPermission_FWD_DEFINED__ */


#ifndef __IMAPFolderPermissions_FWD_DEFINED__
#define __IMAPFolderPermissions_FWD_DEFINED__

#ifdef __cplusplus
typedef class IMAPFolderPermissions IMAPFolderPermissions;
#else
typedef struct IMAPFolderPermissions IMAPFolderPermissions;
#endif /* __cplusplus */

#endif 	/* __IMAPFolderPermissions_FWD_DEFINED__ */


#ifndef __Directories_FWD_DEFINED__
#define __Directories_FWD_DEFINED__

#ifdef __cplusplus
typedef class Directories Directories;
#else
typedef struct Directories Directories;
#endif /* __cplusplus */

#endif 	/* __Directories_FWD_DEFINED__ */


#ifndef __Languages_FWD_DEFINED__
#define __Languages_FWD_DEFINED__

#ifdef __cplusplus
typedef class Languages Languages;
#else
typedef struct Languages Languages;
#endif /* __cplusplus */

#endif 	/* __Languages_FWD_DEFINED__ */


#ifndef __Links_FWD_DEFINED__
#define __Links_FWD_DEFINED__

#ifdef __cplusplus
typedef class Links Links;
#else
typedef struct Links Links;
#endif /* __cplusplus */

#endif 	/* __Links_FWD_DEFINED__ */


#ifndef __IncomingRelay_FWD_DEFINED__
#define __IncomingRelay_FWD_DEFINED__

#ifdef __cplusplus
typedef class IncomingRelay IncomingRelay;
#else
typedef struct IncomingRelay IncomingRelay;
#endif /* __cplusplus */

#endif 	/* __IncomingRelay_FWD_DEFINED__ */


#ifndef __IncomingRelays_FWD_DEFINED__
#define __IncomingRelays_FWD_DEFINED__

#ifdef __cplusplus
typedef class IncomingRelays IncomingRelays;
#else
typedef struct IncomingRelays IncomingRelays;
#endif /* __cplusplus */

#endif 	/* __IncomingRelays_FWD_DEFINED__ */


#ifndef __MessageIndexing_FWD_DEFINED__
#define __MessageIndexing_FWD_DEFINED__

#ifdef __cplusplus
typedef class MessageIndexing MessageIndexing;
#else
typedef struct MessageIndexing MessageIndexing;
#endif /* __cplusplus */

#endif 	/* __MessageIndexing_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_hMailServer_0000_0000 */
/* [local] */ 

















































































typedef /* [public][public][public][public][helpstring][uuid] */  DECLSPEC_UUID("F58B6982-4C39-11D9-B629-F87B01E1264F") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0001
    {	hDBTypeUnknown	= 0,
	hDBTypeMySQL	= 1,
	hDBTypeMSSQL	= 2,
	hDBTypePostgreSQL	= 3,
	hDBTypeMSSQLCE	= 4
    } 	eDBtype;

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("FD97B388-4C39-11D9-8361-94B829D736A2") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0002
    {	hDeleteEmail	= 0,
	hDeleteAttachments	= 1
    } 	eAntivirusAction;

typedef /* [public][public][helpstring][uuid] */  DECLSPEC_UUID("0005B084-4C3A-11D9-8530-B8CDE3157849") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0003
    {	hStateUnknown	= 0,
	hStateStopped	= 1,
	hStateStarting	= 2,
	hStateRunning	= 3,
	hStateStopping	= 4
    } 	eServerState;

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("027282DE-4C3A-11D9-93CE-D4EDF9405FEE") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0004
    {	hLogDeviceUnknown	= 0,
	hLogDeviceSQL	= 1,
	hLogDeviceFile	= 2
    } 	eLogDevice;

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD00") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0005
    {	hLogFormatDefault	= 1,
	hLogFormatCSA	= 2
    } 	eLogOutputFormat;

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD01") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0006
    {	hAdminLevelNormal	= 0,
	hAdminLevelDomainAdmin	= 1,
	hAdminLevelServerAdmin	= 2
    } 	eAdminLevel;

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD02") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0007
    {	eFTUnknown	= 0,
	eFTFrom	= 1,
	eFTTo	= 2,
	eFTCC	= 3,
	eFTSubject	= 4,
	eFTBody	= 5,
	eFTMessageSize	= 6,
	eFTRecipientList	= 7,
	eFTDeliveryAttempts	= 8
    } 	eRulePredefinedField;

typedef /* [public][public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD03") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0008
    {	eMTUnknown	= 0,
	eMTEquals	= 1,
	eMTContains	= 2,
	eMTLessThan	= 3,
	eMTGreaterThan	= 4,
	eMTRegExMatch	= 5,
	eMTNotContains	= 6,
	eMTNotEquals	= 7,
	eMTWildcard	= 8
    } 	eRuleMatchType;

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD04") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0009
    {	eRAUnknown	= 0,
	eRADeleteEmail	= 1,
	eRAForwardEmail	= 2,
	eRAReply	= 3,
	eRAMoveToImapFolder	= 4,
	eRARunScriptFunction	= 5,
	eRAStopRuleProcessing	= 6,
	eRASetHeaderValue	= 7,
	eRASendUsingRoute	= 8,
	eRACreateCopy	= 9,
	eRABindToAddress	= 10
    } 	eRuleActionType;

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD06") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0010
    {	eLMPublic	= 0,
	eLMMembership	= 1,
	eLMAnnouncement	= 2,
	eLMDomainMembers	= 3,
	eLMServerMembers	= 4
    } 	eDistributionListMode;

typedef /* [public][public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD07") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0011
    {	eSTUnknown	= 0,
	eSTSMTP	= 1,
	eSTSMTPClient	= 2,
	eSTPOP3	= 3,
	eSTPOP3Client	= 4,
	eSTIMAP	= 5
    } 	eSessionType;

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD08") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0012
    {	eSMUnknown	= 0,
	eSMSetIfNotSpecifiedInAccount	= 1,
	eSMOverwriteAccountSignature	= 2,
	eSMAppendToAccountSignature	= 3
    } 	eDomainSignatureMethod;

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD09") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0013
    {	eMFSeen	= 1,
	eMFDeleted	= 2,
	eMFFlagged	= 4,
	eMFAnswered	= 8,
	eMFDraft	= 16,
	eMFRecent	= 32,
	eMFVirusScan	= 64
    } 	eMessageFlag;

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD10") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0014
    {	ePermissionLookup	= 1,
	ePermissionRead	= 2,
	ePermissionWriteSeen	= 4,
	ePermissionWriteOthers	= 8,
	ePermissionInsert	= 16,
	ePermissionPost	= 32,
	ePermissionCreate	= 64,
	ePermissionDeleteMailbox	= 128,
	ePermissionWriteDeleted	= 256,
	ePermissionExpunge	= 512,
	ePermissionAdminister	= 1024
    } 	eACLPermission;

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD11") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0015
    {	ePermissionTypeUser	= 0,
	ePermissionTypeGroup	= 1,
	ePermissionTypeAnyone	= 2
    } 	eACLPermissionType;

typedef /* [public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD12") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0016
    {	eDKNeutral	= 0,
	eDKPass	= 1,
	eDKTempFail	= 2,
	eDKPermFail	= 3
    } 	eDKIMResult;

typedef /* [public][public][public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD13") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0017
    {	eCanonicalizationSimple	= 1,
	eCanonicalizationRelaxed	= 2
    } 	eDKIMCanonicalizationMethod;

typedef /* [public][public][public][helpstring][uuid] */  DECLSPEC_UUID("90745436-4C3F-11D9-AD17-A0BCEA20CD14") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0018
    {	eSHA1	= 1,
	eSHA256	= 2
    } 	eDKIMAlgorithm;

typedef /* [public][public][helpstring][uuid] */  DECLSPEC_UUID("87FDF5A8-567E-4bdd-B5E0-4742D4801A92") 
enum __MIDL___MIDL_itf_hMailServer_0000_0000_0019
    {	eUpdateIMAPFolderUID	= 1
    } 	eMaintenanceOperation;



extern RPC_IF_HANDLE __MIDL_itf_hMailServer_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_hMailServer_0000_0000_v0_0_s_ifspec;

#ifndef __IInterfaceStatus_INTERFACE_DEFINED__
#define __IInterfaceStatus_INTERFACE_DEFINED__

/* interface IInterfaceStatus */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceStatus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C3E2DFFB-BE53-4BE6-BE57-7C5609938CEB")
    IInterfaceStatus : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UndeliveredMessages( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StartTime( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProcessedMessages( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemovedViruses( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemovedSpamMessages( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SessionCount( 
            /* [in] */ eSessionType iType,
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceStatusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceStatus * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceStatus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceStatus * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceStatus * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceStatus * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceStatus * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceStatus * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UndeliveredMessages )( 
            IInterfaceStatus * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StartTime )( 
            IInterfaceStatus * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProcessedMessages )( 
            IInterfaceStatus * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemovedViruses )( 
            IInterfaceStatus * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemovedSpamMessages )( 
            IInterfaceStatus * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SessionCount )( 
            IInterfaceStatus * This,
            /* [in] */ eSessionType iType,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } IInterfaceStatusVtbl;

    interface IInterfaceStatus
    {
        CONST_VTBL struct IInterfaceStatusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceStatus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceStatus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceStatus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceStatus_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceStatus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceStatus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceStatus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceStatus_get_UndeliveredMessages(This,pVal)	\
    ( (This)->lpVtbl -> get_UndeliveredMessages(This,pVal) ) 

#define IInterfaceStatus_get_StartTime(This,pVal)	\
    ( (This)->lpVtbl -> get_StartTime(This,pVal) ) 

#define IInterfaceStatus_get_ProcessedMessages(This,pVal)	\
    ( (This)->lpVtbl -> get_ProcessedMessages(This,pVal) ) 

#define IInterfaceStatus_get_RemovedViruses(This,pVal)	\
    ( (This)->lpVtbl -> get_RemovedViruses(This,pVal) ) 

#define IInterfaceStatus_get_RemovedSpamMessages(This,pVal)	\
    ( (This)->lpVtbl -> get_RemovedSpamMessages(This,pVal) ) 

#define IInterfaceStatus_get_SessionCount(This,iType,pVal)	\
    ( (This)->lpVtbl -> get_SessionCount(This,iType,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceStatus_INTERFACE_DEFINED__ */


#ifndef __IInterfaceSettings_INTERFACE_DEFINED__
#define __IInterfaceSettings_INTERFACE_DEFINED__

/* interface IInterfaceSettings */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A4C709A3-98B2-410D-84F4-EDA999BF0CB2")
    IInterfaceSettings : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxSMTPConnections( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxSMTPConnections( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxPOP3Connections( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxPOP3Connections( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MirrorEMailAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MirrorEMailAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowSMTPAuthPlain( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowSMTPAuthPlain( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DenyMailFromNull( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DenyMailFromNull( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Logging( 
            /* [retval][out] */ IInterfaceLogging **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SecurityRanges( 
            /* [retval][out] */ IInterfaceSecurityRanges **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SMTPNoOfTries( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SMTPNoOfTries( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SMTPMinutesBetweenTry( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SMTPMinutesBetweenTry( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SMTPRelayer( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SMTPRelayer( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WelcomeSMTP( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WelcomeSMTP( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WelcomePOP3( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WelcomePOP3( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WelcomeIMAP( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WelcomeIMAP( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServiceSMTP( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ServiceSMTP( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServicePOP3( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ServicePOP3( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServiceIMAP( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ServiceIMAP( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxDeliveryThreads( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxDeliveryThreads( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AntiVirus( 
            /* [retval][out] */ IInterfaceAntiVirus **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Routes( 
            /* [retval][out] */ IInterfaceRoutes **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SendStatistics( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SendStatistics( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HostName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HostName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SMTPRelayerRequiresAuthentication( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SMTPRelayerRequiresAuthentication( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SMTPRelayerUsername( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SMTPRelayerUsername( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSMTPRelayerPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SMTPRelayerPort( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SMTPRelayerPort( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UserInterfaceLanguage( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UserInterfaceLanguage( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Scripting( 
            /* [retval][out] */ IInterfaceScripting **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxMessageSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxMessageSize( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Cache( 
            /* [retval][out] */ IInterfaceCache **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RuleLoopLimit( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RuleLoopLimit( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Backup( 
            /* [retval][out] */ IInterfaceBackupSettings **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultDomain( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultDomain( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SMTPDeliveryBindToIP( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SMTPDeliveryBindToIP( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxIMAPConnections( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxIMAPConnections( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IMAPSortEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IMAPSortEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IMAPQuotaEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IMAPQuotaEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IMAPIdleEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IMAPIdleEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WorkerThreadPriority( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_WorkerThreadPriority( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TCPIPThreads( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TCPIPThreads( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowIncorrectLineEndings( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowIncorrectLineEndings( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxSMTPRecipientsInBatch( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxSMTPRecipientsInBatch( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AntiSpam( 
            /* [retval][out] */ IInterfaceAntiSpam **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisconnectInvalidClients( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DisconnectInvalidClients( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxNumberOfInvalidCommands( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxNumberOfInvalidCommands( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServerMessages( 
            /* [retval][out] */ IInterfaceServerMessages **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TCPIPPorts( 
            /* [retval][out] */ IInterfaceTCPIPPorts **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SMTPRelayerUseSSL( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SMTPRelayerUseSSL( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SSLCertificates( 
            /* [retval][out] */ IInterfaceSSLCertificates **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AddDeliveredToHeader( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AddDeliveredToHeader( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IMAPPublicFolderName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IMAPPublicFolderName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IMAPACLEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IMAPACLEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAdministratorPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Directories( 
            /* [retval][out] */ IInterfaceDirectories **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublicFolders( 
            /* [retval][out] */ IInterfaceIMAPFolders **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PublicFolderDiskName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Groups( 
            /* [retval][out] */ IInterfaceGroups **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IncomingRelays( 
            /* [retval][out] */ IInterfaceIncomingRelays **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoBanOnLogonFailure( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoBanOnLogonFailure( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxInvalidLogonAttempts( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxInvalidLogonAttempts( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxInvalidLogonAttemptsWithin( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxInvalidLogonAttemptsWithin( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AutoBanMinutes( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AutoBanMinutes( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearLogonFailureList( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IMAPHierarchyDelimiter( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IMAPHierarchyDelimiter( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxAsynchronousThreads( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxAsynchronousThreads( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MessageIndexing( 
            /* [retval][out] */ IInterfaceMessageIndexing **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxNumberOfMXHosts( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxNumberOfMXHosts( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceSettings * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceSettings * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceSettings * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceSettings * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceSettings * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceSettings * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxSMTPConnections )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxSMTPConnections )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxPOP3Connections )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxPOP3Connections )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MirrorEMailAddress )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MirrorEMailAddress )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowSMTPAuthPlain )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowSMTPAuthPlain )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DenyMailFromNull )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DenyMailFromNull )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Logging )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceLogging **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SecurityRanges )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceSecurityRanges **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SMTPNoOfTries )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SMTPNoOfTries )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SMTPMinutesBetweenTry )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SMTPMinutesBetweenTry )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SMTPRelayer )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SMTPRelayer )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WelcomeSMTP )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WelcomeSMTP )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WelcomePOP3 )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WelcomePOP3 )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WelcomeIMAP )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WelcomeIMAP )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceSMTP )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ServiceSMTP )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServicePOP3 )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ServicePOP3 )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServiceIMAP )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ServiceIMAP )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxDeliveryThreads )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxDeliveryThreads )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AntiVirus )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceAntiVirus **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Routes )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceRoutes **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SendStatistics )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SendStatistics )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HostName )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HostName )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SMTPRelayerRequiresAuthentication )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SMTPRelayerRequiresAuthentication )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SMTPRelayerUsername )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SMTPRelayerUsername )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSMTPRelayerPassword )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SMTPRelayerPort )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SMTPRelayerPort )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UserInterfaceLanguage )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UserInterfaceLanguage )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Scripting )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceScripting **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxMessageSize )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxMessageSize )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Cache )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceCache **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RuleLoopLimit )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RuleLoopLimit )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Backup )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceBackupSettings **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultDomain )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultDomain )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SMTPDeliveryBindToIP )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SMTPDeliveryBindToIP )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxIMAPConnections )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxIMAPConnections )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IMAPSortEnabled )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IMAPSortEnabled )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IMAPQuotaEnabled )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IMAPQuotaEnabled )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IMAPIdleEnabled )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IMAPIdleEnabled )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WorkerThreadPriority )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WorkerThreadPriority )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TCPIPThreads )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TCPIPThreads )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowIncorrectLineEndings )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowIncorrectLineEndings )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxSMTPRecipientsInBatch )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxSMTPRecipientsInBatch )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AntiSpam )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceAntiSpam **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisconnectInvalidClients )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisconnectInvalidClients )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxNumberOfInvalidCommands )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxNumberOfInvalidCommands )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServerMessages )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceServerMessages **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TCPIPPorts )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceTCPIPPorts **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SMTPRelayerUseSSL )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SMTPRelayerUseSSL )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SSLCertificates )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceSSLCertificates **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AddDeliveredToHeader )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AddDeliveredToHeader )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IMAPPublicFolderName )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IMAPPublicFolderName )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IMAPACLEnabled )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IMAPACLEnabled )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAdministratorPassword )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Directories )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceDirectories **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PublicFolders )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceIMAPFolders **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PublicFolderDiskName )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Groups )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceGroups **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IncomingRelays )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceIncomingRelays **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoBanOnLogonFailure )( 
            IInterfaceSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoBanOnLogonFailure )( 
            IInterfaceSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxInvalidLogonAttempts )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxInvalidLogonAttempts )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxInvalidLogonAttemptsWithin )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxInvalidLogonAttemptsWithin )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoBanMinutes )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoBanMinutes )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearLogonFailureList )( 
            IInterfaceSettings * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IMAPHierarchyDelimiter )( 
            IInterfaceSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IMAPHierarchyDelimiter )( 
            IInterfaceSettings * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxAsynchronousThreads )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxAsynchronousThreads )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MessageIndexing )( 
            IInterfaceSettings * This,
            /* [retval][out] */ IInterfaceMessageIndexing **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxNumberOfMXHosts )( 
            IInterfaceSettings * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxNumberOfMXHosts )( 
            IInterfaceSettings * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IInterfaceSettingsVtbl;

    interface IInterfaceSettings
    {
        CONST_VTBL struct IInterfaceSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceSettings_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceSettings_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceSettings_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceSettings_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceSettings_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceSettings_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceSettings_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceSettings_get_MaxSMTPConnections(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxSMTPConnections(This,pVal) ) 

#define IInterfaceSettings_put_MaxSMTPConnections(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxSMTPConnections(This,newVal) ) 

#define IInterfaceSettings_get_MaxPOP3Connections(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxPOP3Connections(This,pVal) ) 

#define IInterfaceSettings_put_MaxPOP3Connections(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxPOP3Connections(This,newVal) ) 

#define IInterfaceSettings_get_MirrorEMailAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_MirrorEMailAddress(This,pVal) ) 

#define IInterfaceSettings_put_MirrorEMailAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_MirrorEMailAddress(This,newVal) ) 

#define IInterfaceSettings_get_AllowSMTPAuthPlain(This,pVal)	\
    ( (This)->lpVtbl -> get_AllowSMTPAuthPlain(This,pVal) ) 

#define IInterfaceSettings_put_AllowSMTPAuthPlain(This,newVal)	\
    ( (This)->lpVtbl -> put_AllowSMTPAuthPlain(This,newVal) ) 

#define IInterfaceSettings_get_DenyMailFromNull(This,pVal)	\
    ( (This)->lpVtbl -> get_DenyMailFromNull(This,pVal) ) 

#define IInterfaceSettings_put_DenyMailFromNull(This,newVal)	\
    ( (This)->lpVtbl -> put_DenyMailFromNull(This,newVal) ) 

#define IInterfaceSettings_get_Logging(This,pVal)	\
    ( (This)->lpVtbl -> get_Logging(This,pVal) ) 

#define IInterfaceSettings_get_SecurityRanges(This,pVal)	\
    ( (This)->lpVtbl -> get_SecurityRanges(This,pVal) ) 

#define IInterfaceSettings_get_SMTPNoOfTries(This,pVal)	\
    ( (This)->lpVtbl -> get_SMTPNoOfTries(This,pVal) ) 

#define IInterfaceSettings_put_SMTPNoOfTries(This,newVal)	\
    ( (This)->lpVtbl -> put_SMTPNoOfTries(This,newVal) ) 

#define IInterfaceSettings_get_SMTPMinutesBetweenTry(This,pVal)	\
    ( (This)->lpVtbl -> get_SMTPMinutesBetweenTry(This,pVal) ) 

#define IInterfaceSettings_put_SMTPMinutesBetweenTry(This,newVal)	\
    ( (This)->lpVtbl -> put_SMTPMinutesBetweenTry(This,newVal) ) 

#define IInterfaceSettings_get_SMTPRelayer(This,pVal)	\
    ( (This)->lpVtbl -> get_SMTPRelayer(This,pVal) ) 

#define IInterfaceSettings_put_SMTPRelayer(This,newVal)	\
    ( (This)->lpVtbl -> put_SMTPRelayer(This,newVal) ) 

#define IInterfaceSettings_get_WelcomeSMTP(This,pVal)	\
    ( (This)->lpVtbl -> get_WelcomeSMTP(This,pVal) ) 

#define IInterfaceSettings_put_WelcomeSMTP(This,newVal)	\
    ( (This)->lpVtbl -> put_WelcomeSMTP(This,newVal) ) 

#define IInterfaceSettings_get_WelcomePOP3(This,pVal)	\
    ( (This)->lpVtbl -> get_WelcomePOP3(This,pVal) ) 

#define IInterfaceSettings_put_WelcomePOP3(This,newVal)	\
    ( (This)->lpVtbl -> put_WelcomePOP3(This,newVal) ) 

#define IInterfaceSettings_get_WelcomeIMAP(This,pVal)	\
    ( (This)->lpVtbl -> get_WelcomeIMAP(This,pVal) ) 

#define IInterfaceSettings_put_WelcomeIMAP(This,newVal)	\
    ( (This)->lpVtbl -> put_WelcomeIMAP(This,newVal) ) 

#define IInterfaceSettings_get_ServiceSMTP(This,pVal)	\
    ( (This)->lpVtbl -> get_ServiceSMTP(This,pVal) ) 

#define IInterfaceSettings_put_ServiceSMTP(This,newVal)	\
    ( (This)->lpVtbl -> put_ServiceSMTP(This,newVal) ) 

#define IInterfaceSettings_get_ServicePOP3(This,pVal)	\
    ( (This)->lpVtbl -> get_ServicePOP3(This,pVal) ) 

#define IInterfaceSettings_put_ServicePOP3(This,newVal)	\
    ( (This)->lpVtbl -> put_ServicePOP3(This,newVal) ) 

#define IInterfaceSettings_get_ServiceIMAP(This,pVal)	\
    ( (This)->lpVtbl -> get_ServiceIMAP(This,pVal) ) 

#define IInterfaceSettings_put_ServiceIMAP(This,newVal)	\
    ( (This)->lpVtbl -> put_ServiceIMAP(This,newVal) ) 

#define IInterfaceSettings_get_MaxDeliveryThreads(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxDeliveryThreads(This,pVal) ) 

#define IInterfaceSettings_put_MaxDeliveryThreads(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxDeliveryThreads(This,newVal) ) 

#define IInterfaceSettings_get_AntiVirus(This,pVal)	\
    ( (This)->lpVtbl -> get_AntiVirus(This,pVal) ) 

#define IInterfaceSettings_get_Routes(This,pVal)	\
    ( (This)->lpVtbl -> get_Routes(This,pVal) ) 

#define IInterfaceSettings_get_SendStatistics(This,pVal)	\
    ( (This)->lpVtbl -> get_SendStatistics(This,pVal) ) 

#define IInterfaceSettings_put_SendStatistics(This,newVal)	\
    ( (This)->lpVtbl -> put_SendStatistics(This,newVal) ) 

#define IInterfaceSettings_get_HostName(This,pVal)	\
    ( (This)->lpVtbl -> get_HostName(This,pVal) ) 

#define IInterfaceSettings_put_HostName(This,newVal)	\
    ( (This)->lpVtbl -> put_HostName(This,newVal) ) 

#define IInterfaceSettings_get_SMTPRelayerRequiresAuthentication(This,pVal)	\
    ( (This)->lpVtbl -> get_SMTPRelayerRequiresAuthentication(This,pVal) ) 

#define IInterfaceSettings_put_SMTPRelayerRequiresAuthentication(This,newVal)	\
    ( (This)->lpVtbl -> put_SMTPRelayerRequiresAuthentication(This,newVal) ) 

#define IInterfaceSettings_get_SMTPRelayerUsername(This,pVal)	\
    ( (This)->lpVtbl -> get_SMTPRelayerUsername(This,pVal) ) 

#define IInterfaceSettings_put_SMTPRelayerUsername(This,newVal)	\
    ( (This)->lpVtbl -> put_SMTPRelayerUsername(This,newVal) ) 

#define IInterfaceSettings_SetSMTPRelayerPassword(This,newVal)	\
    ( (This)->lpVtbl -> SetSMTPRelayerPassword(This,newVal) ) 

#define IInterfaceSettings_get_SMTPRelayerPort(This,pVal)	\
    ( (This)->lpVtbl -> get_SMTPRelayerPort(This,pVal) ) 

#define IInterfaceSettings_put_SMTPRelayerPort(This,newVal)	\
    ( (This)->lpVtbl -> put_SMTPRelayerPort(This,newVal) ) 

#define IInterfaceSettings_get_UserInterfaceLanguage(This,pVal)	\
    ( (This)->lpVtbl -> get_UserInterfaceLanguage(This,pVal) ) 

#define IInterfaceSettings_put_UserInterfaceLanguage(This,newVal)	\
    ( (This)->lpVtbl -> put_UserInterfaceLanguage(This,newVal) ) 

#define IInterfaceSettings_get_Scripting(This,pVal)	\
    ( (This)->lpVtbl -> get_Scripting(This,pVal) ) 

#define IInterfaceSettings_get_MaxMessageSize(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxMessageSize(This,pVal) ) 

#define IInterfaceSettings_put_MaxMessageSize(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxMessageSize(This,newVal) ) 

#define IInterfaceSettings_get_Cache(This,pVal)	\
    ( (This)->lpVtbl -> get_Cache(This,pVal) ) 

#define IInterfaceSettings_get_RuleLoopLimit(This,pVal)	\
    ( (This)->lpVtbl -> get_RuleLoopLimit(This,pVal) ) 

#define IInterfaceSettings_put_RuleLoopLimit(This,newVal)	\
    ( (This)->lpVtbl -> put_RuleLoopLimit(This,newVal) ) 

#define IInterfaceSettings_get_Backup(This,pVal)	\
    ( (This)->lpVtbl -> get_Backup(This,pVal) ) 

#define IInterfaceSettings_get_DefaultDomain(This,pVal)	\
    ( (This)->lpVtbl -> get_DefaultDomain(This,pVal) ) 

#define IInterfaceSettings_put_DefaultDomain(This,newVal)	\
    ( (This)->lpVtbl -> put_DefaultDomain(This,newVal) ) 

#define IInterfaceSettings_get_SMTPDeliveryBindToIP(This,pVal)	\
    ( (This)->lpVtbl -> get_SMTPDeliveryBindToIP(This,pVal) ) 

#define IInterfaceSettings_put_SMTPDeliveryBindToIP(This,newVal)	\
    ( (This)->lpVtbl -> put_SMTPDeliveryBindToIP(This,newVal) ) 

#define IInterfaceSettings_get_MaxIMAPConnections(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxIMAPConnections(This,pVal) ) 

#define IInterfaceSettings_put_MaxIMAPConnections(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxIMAPConnections(This,newVal) ) 

#define IInterfaceSettings_get_IMAPSortEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_IMAPSortEnabled(This,pVal) ) 

#define IInterfaceSettings_put_IMAPSortEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_IMAPSortEnabled(This,newVal) ) 

#define IInterfaceSettings_get_IMAPQuotaEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_IMAPQuotaEnabled(This,pVal) ) 

#define IInterfaceSettings_put_IMAPQuotaEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_IMAPQuotaEnabled(This,newVal) ) 

#define IInterfaceSettings_get_IMAPIdleEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_IMAPIdleEnabled(This,pVal) ) 

#define IInterfaceSettings_put_IMAPIdleEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_IMAPIdleEnabled(This,newVal) ) 

#define IInterfaceSettings_get_WorkerThreadPriority(This,pVal)	\
    ( (This)->lpVtbl -> get_WorkerThreadPriority(This,pVal) ) 

#define IInterfaceSettings_put_WorkerThreadPriority(This,newVal)	\
    ( (This)->lpVtbl -> put_WorkerThreadPriority(This,newVal) ) 

#define IInterfaceSettings_get_TCPIPThreads(This,pVal)	\
    ( (This)->lpVtbl -> get_TCPIPThreads(This,pVal) ) 

#define IInterfaceSettings_put_TCPIPThreads(This,newVal)	\
    ( (This)->lpVtbl -> put_TCPIPThreads(This,newVal) ) 

#define IInterfaceSettings_get_AllowIncorrectLineEndings(This,pVal)	\
    ( (This)->lpVtbl -> get_AllowIncorrectLineEndings(This,pVal) ) 

#define IInterfaceSettings_put_AllowIncorrectLineEndings(This,newVal)	\
    ( (This)->lpVtbl -> put_AllowIncorrectLineEndings(This,newVal) ) 

#define IInterfaceSettings_get_MaxSMTPRecipientsInBatch(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxSMTPRecipientsInBatch(This,pVal) ) 

#define IInterfaceSettings_put_MaxSMTPRecipientsInBatch(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxSMTPRecipientsInBatch(This,newVal) ) 

#define IInterfaceSettings_get_AntiSpam(This,pVal)	\
    ( (This)->lpVtbl -> get_AntiSpam(This,pVal) ) 

#define IInterfaceSettings_get_DisconnectInvalidClients(This,pVal)	\
    ( (This)->lpVtbl -> get_DisconnectInvalidClients(This,pVal) ) 

#define IInterfaceSettings_put_DisconnectInvalidClients(This,newVal)	\
    ( (This)->lpVtbl -> put_DisconnectInvalidClients(This,newVal) ) 

#define IInterfaceSettings_get_MaxNumberOfInvalidCommands(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxNumberOfInvalidCommands(This,pVal) ) 

#define IInterfaceSettings_put_MaxNumberOfInvalidCommands(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxNumberOfInvalidCommands(This,newVal) ) 

#define IInterfaceSettings_get_ServerMessages(This,pVal)	\
    ( (This)->lpVtbl -> get_ServerMessages(This,pVal) ) 

#define IInterfaceSettings_get_TCPIPPorts(This,pVal)	\
    ( (This)->lpVtbl -> get_TCPIPPorts(This,pVal) ) 

#define IInterfaceSettings_get_SMTPRelayerUseSSL(This,pVal)	\
    ( (This)->lpVtbl -> get_SMTPRelayerUseSSL(This,pVal) ) 

#define IInterfaceSettings_put_SMTPRelayerUseSSL(This,newVal)	\
    ( (This)->lpVtbl -> put_SMTPRelayerUseSSL(This,newVal) ) 

#define IInterfaceSettings_get_SSLCertificates(This,pVal)	\
    ( (This)->lpVtbl -> get_SSLCertificates(This,pVal) ) 

#define IInterfaceSettings_get_AddDeliveredToHeader(This,pVal)	\
    ( (This)->lpVtbl -> get_AddDeliveredToHeader(This,pVal) ) 

#define IInterfaceSettings_put_AddDeliveredToHeader(This,newVal)	\
    ( (This)->lpVtbl -> put_AddDeliveredToHeader(This,newVal) ) 

#define IInterfaceSettings_get_IMAPPublicFolderName(This,pVal)	\
    ( (This)->lpVtbl -> get_IMAPPublicFolderName(This,pVal) ) 

#define IInterfaceSettings_put_IMAPPublicFolderName(This,newVal)	\
    ( (This)->lpVtbl -> put_IMAPPublicFolderName(This,newVal) ) 

#define IInterfaceSettings_get_IMAPACLEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_IMAPACLEnabled(This,pVal) ) 

#define IInterfaceSettings_put_IMAPACLEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_IMAPACLEnabled(This,newVal) ) 

#define IInterfaceSettings_SetAdministratorPassword(This,newVal)	\
    ( (This)->lpVtbl -> SetAdministratorPassword(This,newVal) ) 

#define IInterfaceSettings_get_Directories(This,pVal)	\
    ( (This)->lpVtbl -> get_Directories(This,pVal) ) 

#define IInterfaceSettings_get_PublicFolders(This,pVal)	\
    ( (This)->lpVtbl -> get_PublicFolders(This,pVal) ) 

#define IInterfaceSettings_get_PublicFolderDiskName(This,pVal)	\
    ( (This)->lpVtbl -> get_PublicFolderDiskName(This,pVal) ) 

#define IInterfaceSettings_get_Groups(This,pVal)	\
    ( (This)->lpVtbl -> get_Groups(This,pVal) ) 

#define IInterfaceSettings_get_IncomingRelays(This,pVal)	\
    ( (This)->lpVtbl -> get_IncomingRelays(This,pVal) ) 

#define IInterfaceSettings_get_AutoBanOnLogonFailure(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoBanOnLogonFailure(This,pVal) ) 

#define IInterfaceSettings_put_AutoBanOnLogonFailure(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoBanOnLogonFailure(This,newVal) ) 

#define IInterfaceSettings_get_MaxInvalidLogonAttempts(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxInvalidLogonAttempts(This,pVal) ) 

#define IInterfaceSettings_put_MaxInvalidLogonAttempts(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxInvalidLogonAttempts(This,newVal) ) 

#define IInterfaceSettings_get_MaxInvalidLogonAttemptsWithin(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxInvalidLogonAttemptsWithin(This,pVal) ) 

#define IInterfaceSettings_put_MaxInvalidLogonAttemptsWithin(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxInvalidLogonAttemptsWithin(This,newVal) ) 

#define IInterfaceSettings_get_AutoBanMinutes(This,pVal)	\
    ( (This)->lpVtbl -> get_AutoBanMinutes(This,pVal) ) 

#define IInterfaceSettings_put_AutoBanMinutes(This,newVal)	\
    ( (This)->lpVtbl -> put_AutoBanMinutes(This,newVal) ) 

#define IInterfaceSettings_ClearLogonFailureList(This)	\
    ( (This)->lpVtbl -> ClearLogonFailureList(This) ) 

#define IInterfaceSettings_get_IMAPHierarchyDelimiter(This,pVal)	\
    ( (This)->lpVtbl -> get_IMAPHierarchyDelimiter(This,pVal) ) 

#define IInterfaceSettings_put_IMAPHierarchyDelimiter(This,newVal)	\
    ( (This)->lpVtbl -> put_IMAPHierarchyDelimiter(This,newVal) ) 

#define IInterfaceSettings_get_MaxAsynchronousThreads(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxAsynchronousThreads(This,pVal) ) 

#define IInterfaceSettings_put_MaxAsynchronousThreads(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxAsynchronousThreads(This,newVal) ) 

#define IInterfaceSettings_get_MessageIndexing(This,pVal)	\
    ( (This)->lpVtbl -> get_MessageIndexing(This,pVal) ) 

#define IInterfaceSettings_get_MaxNumberOfMXHosts(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxNumberOfMXHosts(This,pVal) ) 

#define IInterfaceSettings_put_MaxNumberOfMXHosts(This,newVal)	\
    ( (This)->lpVtbl -> put_MaxNumberOfMXHosts(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceSettings_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDomain_INTERFACE_DEFINED__
#define __IInterfaceDomain_INTERFACE_DEFINED__

/* interface IInterfaceDomain */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDomain;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3F50C3AF-67C0-4628-91D6-E2EAC7786830")
    IInterfaceDomain : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Active( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Accounts( 
            /* [retval][out] */ IInterfaceAccounts **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Aliases( 
            /* [retval][out] */ IInterfaceAliases **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DistributionLists( 
            /* [retval][out] */ IInterfaceDistributionLists **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Postmaster( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Postmaster( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainAliases( 
            /* [retval][out] */ IInterfaceDomainAliases **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ADDomainName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ADDomainName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SynchronizeDirectory( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxMessageSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxMessageSize( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlusAddressingEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PlusAddressingEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PlusAddressingCharacter( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PlusAddressingCharacter( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AntiSpamEnableGreylisting( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AntiSpamEnableGreylisting( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxSize( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllocatedSize( 
            /* [retval][out] */ hyper *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SignatureEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SignatureEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SignatureMethod( 
            /* [retval][out] */ eDomainSignatureMethod *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SignatureMethod( 
            /* [in] */ eDomainSignatureMethod newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SignaturePlainText( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SignaturePlainText( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SignatureHTML( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SignatureHTML( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AddSignaturesToReplies( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AddSignaturesToReplies( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AddSignaturesToLocalMail( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AddSignaturesToLocalMail( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxNumberOfAccounts( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxNumberOfAccounts( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxNumberOfAliases( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxNumberOfAliases( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxNumberOfDistributionLists( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxNumberOfDistributionLists( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxNumberOfAccountsEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxNumberOfAccountsEnabled( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxNumberOfAliasesEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxNumberOfAliasesEnabled( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxNumberOfDistributionListsEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxNumberOfDistributionListsEnabled( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxAccountSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxAccountSize( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DKIMSignEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DKIMSignEnabled( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DKIMSelector( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DKIMSelector( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DKIMPrivateKeyFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DKIMPrivateKeyFile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DKIMHeaderCanonicalizationMethod( 
            /* [retval][out] */ eDKIMCanonicalizationMethod *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DKIMHeaderCanonicalizationMethod( 
            /* [in] */ eDKIMCanonicalizationMethod newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DKIMBodyCanonicalizationMethod( 
            /* [retval][out] */ eDKIMCanonicalizationMethod *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DKIMBodyCanonicalizationMethod( 
            /* [in] */ eDKIMCanonicalizationMethod newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DKIMSigningAlgorithm( 
            /* [retval][out] */ eDKIMAlgorithm *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DKIMSigningAlgorithm( 
            /* [in] */ eDKIMAlgorithm newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDomainVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDomain * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDomain * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDomain * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDomain * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDomain * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDomain * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDomain * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceDomain * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IInterfaceDomain * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceDomain * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceDomain * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Active )( 
            IInterfaceDomain * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Active )( 
            IInterfaceDomain * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Accounts )( 
            IInterfaceDomain * This,
            /* [retval][out] */ IInterfaceAccounts **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceDomain * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Aliases )( 
            IInterfaceDomain * This,
            /* [retval][out] */ IInterfaceAliases **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DistributionLists )( 
            IInterfaceDomain * This,
            /* [retval][out] */ IInterfaceDistributionLists **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Postmaster )( 
            IInterfaceDomain * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Postmaster )( 
            IInterfaceDomain * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DomainAliases )( 
            IInterfaceDomain * This,
            /* [retval][out] */ IInterfaceDomainAliases **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ADDomainName )( 
            IInterfaceDomain * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ADDomainName )( 
            IInterfaceDomain * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SynchronizeDirectory )( 
            IInterfaceDomain * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxMessageSize )( 
            IInterfaceDomain * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxMessageSize )( 
            IInterfaceDomain * This,
            /* [in] */ long pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlusAddressingEnabled )( 
            IInterfaceDomain * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PlusAddressingEnabled )( 
            IInterfaceDomain * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlusAddressingCharacter )( 
            IInterfaceDomain * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PlusAddressingCharacter )( 
            IInterfaceDomain * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AntiSpamEnableGreylisting )( 
            IInterfaceDomain * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AntiSpamEnableGreylisting )( 
            IInterfaceDomain * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxSize )( 
            IInterfaceDomain * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxSize )( 
            IInterfaceDomain * This,
            /* [in] */ long pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IInterfaceDomain * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllocatedSize )( 
            IInterfaceDomain * This,
            /* [retval][out] */ hyper *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SignatureEnabled )( 
            IInterfaceDomain * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SignatureEnabled )( 
            IInterfaceDomain * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SignatureMethod )( 
            IInterfaceDomain * This,
            /* [retval][out] */ eDomainSignatureMethod *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SignatureMethod )( 
            IInterfaceDomain * This,
            /* [in] */ eDomainSignatureMethod newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SignaturePlainText )( 
            IInterfaceDomain * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SignaturePlainText )( 
            IInterfaceDomain * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SignatureHTML )( 
            IInterfaceDomain * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SignatureHTML )( 
            IInterfaceDomain * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AddSignaturesToReplies )( 
            IInterfaceDomain * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AddSignaturesToReplies )( 
            IInterfaceDomain * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AddSignaturesToLocalMail )( 
            IInterfaceDomain * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AddSignaturesToLocalMail )( 
            IInterfaceDomain * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxNumberOfAccounts )( 
            IInterfaceDomain * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxNumberOfAccounts )( 
            IInterfaceDomain * This,
            /* [in] */ long pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxNumberOfAliases )( 
            IInterfaceDomain * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxNumberOfAliases )( 
            IInterfaceDomain * This,
            /* [in] */ long pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxNumberOfDistributionLists )( 
            IInterfaceDomain * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxNumberOfDistributionLists )( 
            IInterfaceDomain * This,
            /* [in] */ long pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxNumberOfAccountsEnabled )( 
            IInterfaceDomain * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxNumberOfAccountsEnabled )( 
            IInterfaceDomain * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxNumberOfAliasesEnabled )( 
            IInterfaceDomain * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxNumberOfAliasesEnabled )( 
            IInterfaceDomain * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxNumberOfDistributionListsEnabled )( 
            IInterfaceDomain * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxNumberOfDistributionListsEnabled )( 
            IInterfaceDomain * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxAccountSize )( 
            IInterfaceDomain * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxAccountSize )( 
            IInterfaceDomain * This,
            /* [in] */ long pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DKIMSignEnabled )( 
            IInterfaceDomain * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DKIMSignEnabled )( 
            IInterfaceDomain * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DKIMSelector )( 
            IInterfaceDomain * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DKIMSelector )( 
            IInterfaceDomain * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DKIMPrivateKeyFile )( 
            IInterfaceDomain * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DKIMPrivateKeyFile )( 
            IInterfaceDomain * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DKIMHeaderCanonicalizationMethod )( 
            IInterfaceDomain * This,
            /* [retval][out] */ eDKIMCanonicalizationMethod *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DKIMHeaderCanonicalizationMethod )( 
            IInterfaceDomain * This,
            /* [in] */ eDKIMCanonicalizationMethod newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DKIMBodyCanonicalizationMethod )( 
            IInterfaceDomain * This,
            /* [retval][out] */ eDKIMCanonicalizationMethod *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DKIMBodyCanonicalizationMethod )( 
            IInterfaceDomain * This,
            /* [in] */ eDKIMCanonicalizationMethod newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DKIMSigningAlgorithm )( 
            IInterfaceDomain * This,
            /* [retval][out] */ eDKIMAlgorithm *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DKIMSigningAlgorithm )( 
            IInterfaceDomain * This,
            /* [in] */ eDKIMAlgorithm newVal);
        
        END_INTERFACE
    } IInterfaceDomainVtbl;

    interface IInterfaceDomain
    {
        CONST_VTBL struct IInterfaceDomainVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDomain_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDomain_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDomain_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDomain_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDomain_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDomain_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDomain_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDomain_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceDomain_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IInterfaceDomain_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceDomain_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceDomain_get_Active(This,pVal)	\
    ( (This)->lpVtbl -> get_Active(This,pVal) ) 

#define IInterfaceDomain_put_Active(This,newVal)	\
    ( (This)->lpVtbl -> put_Active(This,newVal) ) 

#define IInterfaceDomain_get_Accounts(This,pVal)	\
    ( (This)->lpVtbl -> get_Accounts(This,pVal) ) 

#define IInterfaceDomain_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IInterfaceDomain_get_Aliases(This,pVal)	\
    ( (This)->lpVtbl -> get_Aliases(This,pVal) ) 

#define IInterfaceDomain_get_DistributionLists(This,pVal)	\
    ( (This)->lpVtbl -> get_DistributionLists(This,pVal) ) 

#define IInterfaceDomain_get_Postmaster(This,pVal)	\
    ( (This)->lpVtbl -> get_Postmaster(This,pVal) ) 

#define IInterfaceDomain_put_Postmaster(This,newVal)	\
    ( (This)->lpVtbl -> put_Postmaster(This,newVal) ) 

#define IInterfaceDomain_get_DomainAliases(This,pVal)	\
    ( (This)->lpVtbl -> get_DomainAliases(This,pVal) ) 

#define IInterfaceDomain_get_ADDomainName(This,pVal)	\
    ( (This)->lpVtbl -> get_ADDomainName(This,pVal) ) 

#define IInterfaceDomain_put_ADDomainName(This,newVal)	\
    ( (This)->lpVtbl -> put_ADDomainName(This,newVal) ) 

#define IInterfaceDomain_SynchronizeDirectory(This)	\
    ( (This)->lpVtbl -> SynchronizeDirectory(This) ) 

#define IInterfaceDomain_get_MaxMessageSize(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxMessageSize(This,pVal) ) 

#define IInterfaceDomain_put_MaxMessageSize(This,pVal)	\
    ( (This)->lpVtbl -> put_MaxMessageSize(This,pVal) ) 

#define IInterfaceDomain_get_PlusAddressingEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_PlusAddressingEnabled(This,pVal) ) 

#define IInterfaceDomain_put_PlusAddressingEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_PlusAddressingEnabled(This,newVal) ) 

#define IInterfaceDomain_get_PlusAddressingCharacter(This,pVal)	\
    ( (This)->lpVtbl -> get_PlusAddressingCharacter(This,pVal) ) 

#define IInterfaceDomain_put_PlusAddressingCharacter(This,newVal)	\
    ( (This)->lpVtbl -> put_PlusAddressingCharacter(This,newVal) ) 

#define IInterfaceDomain_get_AntiSpamEnableGreylisting(This,pVal)	\
    ( (This)->lpVtbl -> get_AntiSpamEnableGreylisting(This,pVal) ) 

#define IInterfaceDomain_put_AntiSpamEnableGreylisting(This,newVal)	\
    ( (This)->lpVtbl -> put_AntiSpamEnableGreylisting(This,newVal) ) 

#define IInterfaceDomain_get_MaxSize(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxSize(This,pVal) ) 

#define IInterfaceDomain_put_MaxSize(This,pVal)	\
    ( (This)->lpVtbl -> put_MaxSize(This,pVal) ) 

#define IInterfaceDomain_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define IInterfaceDomain_get_AllocatedSize(This,pVal)	\
    ( (This)->lpVtbl -> get_AllocatedSize(This,pVal) ) 

#define IInterfaceDomain_get_SignatureEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_SignatureEnabled(This,pVal) ) 

#define IInterfaceDomain_put_SignatureEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_SignatureEnabled(This,newVal) ) 

#define IInterfaceDomain_get_SignatureMethod(This,pVal)	\
    ( (This)->lpVtbl -> get_SignatureMethod(This,pVal) ) 

#define IInterfaceDomain_put_SignatureMethod(This,newVal)	\
    ( (This)->lpVtbl -> put_SignatureMethod(This,newVal) ) 

#define IInterfaceDomain_get_SignaturePlainText(This,pVal)	\
    ( (This)->lpVtbl -> get_SignaturePlainText(This,pVal) ) 

#define IInterfaceDomain_put_SignaturePlainText(This,newVal)	\
    ( (This)->lpVtbl -> put_SignaturePlainText(This,newVal) ) 

#define IInterfaceDomain_get_SignatureHTML(This,pVal)	\
    ( (This)->lpVtbl -> get_SignatureHTML(This,pVal) ) 

#define IInterfaceDomain_put_SignatureHTML(This,newVal)	\
    ( (This)->lpVtbl -> put_SignatureHTML(This,newVal) ) 

#define IInterfaceDomain_get_AddSignaturesToReplies(This,pVal)	\
    ( (This)->lpVtbl -> get_AddSignaturesToReplies(This,pVal) ) 

#define IInterfaceDomain_put_AddSignaturesToReplies(This,newVal)	\
    ( (This)->lpVtbl -> put_AddSignaturesToReplies(This,newVal) ) 

#define IInterfaceDomain_get_AddSignaturesToLocalMail(This,pVal)	\
    ( (This)->lpVtbl -> get_AddSignaturesToLocalMail(This,pVal) ) 

#define IInterfaceDomain_put_AddSignaturesToLocalMail(This,newVal)	\
    ( (This)->lpVtbl -> put_AddSignaturesToLocalMail(This,newVal) ) 

#define IInterfaceDomain_get_MaxNumberOfAccounts(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxNumberOfAccounts(This,pVal) ) 

#define IInterfaceDomain_put_MaxNumberOfAccounts(This,pVal)	\
    ( (This)->lpVtbl -> put_MaxNumberOfAccounts(This,pVal) ) 

#define IInterfaceDomain_get_MaxNumberOfAliases(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxNumberOfAliases(This,pVal) ) 

#define IInterfaceDomain_put_MaxNumberOfAliases(This,pVal)	\
    ( (This)->lpVtbl -> put_MaxNumberOfAliases(This,pVal) ) 

#define IInterfaceDomain_get_MaxNumberOfDistributionLists(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxNumberOfDistributionLists(This,pVal) ) 

#define IInterfaceDomain_put_MaxNumberOfDistributionLists(This,pVal)	\
    ( (This)->lpVtbl -> put_MaxNumberOfDistributionLists(This,pVal) ) 

#define IInterfaceDomain_get_MaxNumberOfAccountsEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxNumberOfAccountsEnabled(This,pVal) ) 

#define IInterfaceDomain_put_MaxNumberOfAccountsEnabled(This,pVal)	\
    ( (This)->lpVtbl -> put_MaxNumberOfAccountsEnabled(This,pVal) ) 

#define IInterfaceDomain_get_MaxNumberOfAliasesEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxNumberOfAliasesEnabled(This,pVal) ) 

#define IInterfaceDomain_put_MaxNumberOfAliasesEnabled(This,pVal)	\
    ( (This)->lpVtbl -> put_MaxNumberOfAliasesEnabled(This,pVal) ) 

#define IInterfaceDomain_get_MaxNumberOfDistributionListsEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxNumberOfDistributionListsEnabled(This,pVal) ) 

#define IInterfaceDomain_put_MaxNumberOfDistributionListsEnabled(This,pVal)	\
    ( (This)->lpVtbl -> put_MaxNumberOfDistributionListsEnabled(This,pVal) ) 

#define IInterfaceDomain_get_MaxAccountSize(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxAccountSize(This,pVal) ) 

#define IInterfaceDomain_put_MaxAccountSize(This,pVal)	\
    ( (This)->lpVtbl -> put_MaxAccountSize(This,pVal) ) 

#define IInterfaceDomain_get_DKIMSignEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_DKIMSignEnabled(This,pVal) ) 

#define IInterfaceDomain_put_DKIMSignEnabled(This,pVal)	\
    ( (This)->lpVtbl -> put_DKIMSignEnabled(This,pVal) ) 

#define IInterfaceDomain_get_DKIMSelector(This,pVal)	\
    ( (This)->lpVtbl -> get_DKIMSelector(This,pVal) ) 

#define IInterfaceDomain_put_DKIMSelector(This,newVal)	\
    ( (This)->lpVtbl -> put_DKIMSelector(This,newVal) ) 

#define IInterfaceDomain_get_DKIMPrivateKeyFile(This,pVal)	\
    ( (This)->lpVtbl -> get_DKIMPrivateKeyFile(This,pVal) ) 

#define IInterfaceDomain_put_DKIMPrivateKeyFile(This,newVal)	\
    ( (This)->lpVtbl -> put_DKIMPrivateKeyFile(This,newVal) ) 

#define IInterfaceDomain_get_DKIMHeaderCanonicalizationMethod(This,pVal)	\
    ( (This)->lpVtbl -> get_DKIMHeaderCanonicalizationMethod(This,pVal) ) 

#define IInterfaceDomain_put_DKIMHeaderCanonicalizationMethod(This,newVal)	\
    ( (This)->lpVtbl -> put_DKIMHeaderCanonicalizationMethod(This,newVal) ) 

#define IInterfaceDomain_get_DKIMBodyCanonicalizationMethod(This,pVal)	\
    ( (This)->lpVtbl -> get_DKIMBodyCanonicalizationMethod(This,pVal) ) 

#define IInterfaceDomain_put_DKIMBodyCanonicalizationMethod(This,newVal)	\
    ( (This)->lpVtbl -> put_DKIMBodyCanonicalizationMethod(This,newVal) ) 

#define IInterfaceDomain_get_DKIMSigningAlgorithm(This,pVal)	\
    ( (This)->lpVtbl -> get_DKIMSigningAlgorithm(This,pVal) ) 

#define IInterfaceDomain_put_DKIMSigningAlgorithm(This,newVal)	\
    ( (This)->lpVtbl -> put_DKIMSigningAlgorithm(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDomain_INTERFACE_DEFINED__ */


#ifndef __IInterfaceAccounts_INTERFACE_DEFINED__
#define __IInterfaceAccounts_INTERFACE_DEFINED__

/* interface IInterfaceAccounts */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceAccounts;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0AD49AE7-05ED-45F2-8D5A-68FC964EB7EA")
    IInterfaceAccounts : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceAccount **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceAccount **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ long Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceAccount **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByAddress( 
            /* [in] */ BSTR Address,
            /* [retval][out] */ IInterfaceAccount **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceAccountsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceAccounts * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceAccounts * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceAccounts * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceAccounts * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceAccounts * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceAccounts * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceAccounts * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceAccounts * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceAccount **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceAccounts * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceAccounts * This,
            /* [retval][out] */ IInterfaceAccount **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceAccounts * This,
            /* [in] */ long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceAccounts * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceAccounts * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceAccount **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByAddress )( 
            IInterfaceAccounts * This,
            /* [in] */ BSTR Address,
            /* [retval][out] */ IInterfaceAccount **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceAccounts * This,
            /* [in] */ long DBID);
        
        END_INTERFACE
    } IInterfaceAccountsVtbl;

    interface IInterfaceAccounts
    {
        CONST_VTBL struct IInterfaceAccountsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceAccounts_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceAccounts_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceAccounts_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceAccounts_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceAccounts_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceAccounts_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceAccounts_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceAccounts_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceAccounts_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceAccounts_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceAccounts_Delete(This,Index)	\
    ( (This)->lpVtbl -> Delete(This,Index) ) 

#define IInterfaceAccounts_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceAccounts_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceAccounts_get_ItemByAddress(This,Address,pVal)	\
    ( (This)->lpVtbl -> get_ItemByAddress(This,Address,pVal) ) 

#define IInterfaceAccounts_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceAccounts_INTERFACE_DEFINED__ */


#ifndef __IInterfaceAccount_INTERFACE_DEFINED__
#define __IInterfaceAccount_INTERFACE_DEFINED__

/* interface IInterfaceAccount */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceAccount;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E5EDC050-0899-4A3B-BF4C-420212FC3895")
    IInterfaceAccount : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Active( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ADDomain( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ADDomain( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Address( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Address( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DomainID( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsAD( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IsAD( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Password( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ float *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ADUsername( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ADUsername( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteMessages( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Messages( 
            /* [retval][out] */ IInterfaceMessages **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxSize( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VacationMessageIsOn( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VacationMessageIsOn( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VacationMessage( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VacationMessage( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VacationSubject( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VacationSubject( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FetchAccounts( 
            /* [retval][out] */ IInterfaceFetchAccounts **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AdminLevel( 
            /* [retval][out] */ eAdminLevel *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AdminLevel( 
            /* [in] */ eAdminLevel newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rules( 
            /* [retval][out] */ IInterfaceRules **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ValidatePassword( 
            /* [in] */ BSTR Password,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockMailbox( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IMAPFolders( 
            /* [retval][out] */ IInterfaceIMAPFolders **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_QuotaUsed( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ForwardEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ForwardEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ForwardAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ForwardAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ForwardKeepOriginal( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ForwardKeepOriginal( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SignatureEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SignatureEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SignaturePlainText( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SignaturePlainText( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SignatureHTML( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SignatureHTML( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastLogonTime( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VacationMessageExpires( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VacationMessageExpires( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VacationMessageExpiresDate( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VacationMessageExpiresDate( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PersonFirstName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PersonFirstName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PersonLastName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PersonLastName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceAccountVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceAccount * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceAccount * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceAccount * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceAccount * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceAccount * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceAccount * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceAccount * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Active )( 
            IInterfaceAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Active )( 
            IInterfaceAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ADDomain )( 
            IInterfaceAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ADDomain )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Address )( 
            IInterfaceAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Address )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DomainID )( 
            IInterfaceAccount * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DomainID )( 
            IInterfaceAccount * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceAccount * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsAD )( 
            IInterfaceAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsAD )( 
            IInterfaceAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Password )( 
            IInterfaceAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IInterfaceAccount * This,
            /* [retval][out] */ float *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceAccount * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ADUsername )( 
            IInterfaceAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ADUsername )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteMessages )( 
            IInterfaceAccount * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Messages )( 
            IInterfaceAccount * This,
            /* [retval][out] */ IInterfaceMessages **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxSize )( 
            IInterfaceAccount * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxSize )( 
            IInterfaceAccount * This,
            /* [in] */ long pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VacationMessageIsOn )( 
            IInterfaceAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VacationMessageIsOn )( 
            IInterfaceAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VacationMessage )( 
            IInterfaceAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VacationMessage )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VacationSubject )( 
            IInterfaceAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VacationSubject )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FetchAccounts )( 
            IInterfaceAccount * This,
            /* [retval][out] */ IInterfaceFetchAccounts **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AdminLevel )( 
            IInterfaceAccount * This,
            /* [retval][out] */ eAdminLevel *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AdminLevel )( 
            IInterfaceAccount * This,
            /* [in] */ eAdminLevel newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rules )( 
            IInterfaceAccount * This,
            /* [retval][out] */ IInterfaceRules **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ValidatePassword )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR Password,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockMailbox )( 
            IInterfaceAccount * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IMAPFolders )( 
            IInterfaceAccount * This,
            /* [retval][out] */ IInterfaceIMAPFolders **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_QuotaUsed )( 
            IInterfaceAccount * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ForwardEnabled )( 
            IInterfaceAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ForwardEnabled )( 
            IInterfaceAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ForwardAddress )( 
            IInterfaceAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ForwardAddress )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ForwardKeepOriginal )( 
            IInterfaceAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ForwardKeepOriginal )( 
            IInterfaceAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SignatureEnabled )( 
            IInterfaceAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SignatureEnabled )( 
            IInterfaceAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SignaturePlainText )( 
            IInterfaceAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SignaturePlainText )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SignatureHTML )( 
            IInterfaceAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SignatureHTML )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LastLogonTime )( 
            IInterfaceAccount * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VacationMessageExpires )( 
            IInterfaceAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VacationMessageExpires )( 
            IInterfaceAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VacationMessageExpiresDate )( 
            IInterfaceAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VacationMessageExpiresDate )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PersonFirstName )( 
            IInterfaceAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PersonFirstName )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PersonLastName )( 
            IInterfaceAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PersonLastName )( 
            IInterfaceAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceAccount * This);
        
        END_INTERFACE
    } IInterfaceAccountVtbl;

    interface IInterfaceAccount
    {
        CONST_VTBL struct IInterfaceAccountVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceAccount_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceAccount_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceAccount_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceAccount_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceAccount_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceAccount_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceAccount_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceAccount_get_Active(This,pVal)	\
    ( (This)->lpVtbl -> get_Active(This,pVal) ) 

#define IInterfaceAccount_put_Active(This,newVal)	\
    ( (This)->lpVtbl -> put_Active(This,newVal) ) 

#define IInterfaceAccount_get_ADDomain(This,pVal)	\
    ( (This)->lpVtbl -> get_ADDomain(This,pVal) ) 

#define IInterfaceAccount_put_ADDomain(This,newVal)	\
    ( (This)->lpVtbl -> put_ADDomain(This,newVal) ) 

#define IInterfaceAccount_get_Address(This,pVal)	\
    ( (This)->lpVtbl -> get_Address(This,pVal) ) 

#define IInterfaceAccount_put_Address(This,newVal)	\
    ( (This)->lpVtbl -> put_Address(This,newVal) ) 

#define IInterfaceAccount_get_DomainID(This,pVal)	\
    ( (This)->lpVtbl -> get_DomainID(This,pVal) ) 

#define IInterfaceAccount_put_DomainID(This,newVal)	\
    ( (This)->lpVtbl -> put_DomainID(This,newVal) ) 

#define IInterfaceAccount_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceAccount_get_IsAD(This,pVal)	\
    ( (This)->lpVtbl -> get_IsAD(This,pVal) ) 

#define IInterfaceAccount_put_IsAD(This,newVal)	\
    ( (This)->lpVtbl -> put_IsAD(This,newVal) ) 

#define IInterfaceAccount_get_Password(This,pVal)	\
    ( (This)->lpVtbl -> get_Password(This,pVal) ) 

#define IInterfaceAccount_put_Password(This,newVal)	\
    ( (This)->lpVtbl -> put_Password(This,newVal) ) 

#define IInterfaceAccount_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define IInterfaceAccount_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceAccount_get_ADUsername(This,pVal)	\
    ( (This)->lpVtbl -> get_ADUsername(This,pVal) ) 

#define IInterfaceAccount_put_ADUsername(This,newVal)	\
    ( (This)->lpVtbl -> put_ADUsername(This,newVal) ) 

#define IInterfaceAccount_DeleteMessages(This)	\
    ( (This)->lpVtbl -> DeleteMessages(This) ) 

#define IInterfaceAccount_get_Messages(This,pVal)	\
    ( (This)->lpVtbl -> get_Messages(This,pVal) ) 

#define IInterfaceAccount_get_MaxSize(This,pVal)	\
    ( (This)->lpVtbl -> get_MaxSize(This,pVal) ) 

#define IInterfaceAccount_put_MaxSize(This,pVal)	\
    ( (This)->lpVtbl -> put_MaxSize(This,pVal) ) 

#define IInterfaceAccount_get_VacationMessageIsOn(This,pVal)	\
    ( (This)->lpVtbl -> get_VacationMessageIsOn(This,pVal) ) 

#define IInterfaceAccount_put_VacationMessageIsOn(This,newVal)	\
    ( (This)->lpVtbl -> put_VacationMessageIsOn(This,newVal) ) 

#define IInterfaceAccount_get_VacationMessage(This,pVal)	\
    ( (This)->lpVtbl -> get_VacationMessage(This,pVal) ) 

#define IInterfaceAccount_put_VacationMessage(This,newVal)	\
    ( (This)->lpVtbl -> put_VacationMessage(This,newVal) ) 

#define IInterfaceAccount_get_VacationSubject(This,pVal)	\
    ( (This)->lpVtbl -> get_VacationSubject(This,pVal) ) 

#define IInterfaceAccount_put_VacationSubject(This,newVal)	\
    ( (This)->lpVtbl -> put_VacationSubject(This,newVal) ) 

#define IInterfaceAccount_get_FetchAccounts(This,pVal)	\
    ( (This)->lpVtbl -> get_FetchAccounts(This,pVal) ) 

#define IInterfaceAccount_get_AdminLevel(This,pVal)	\
    ( (This)->lpVtbl -> get_AdminLevel(This,pVal) ) 

#define IInterfaceAccount_put_AdminLevel(This,newVal)	\
    ( (This)->lpVtbl -> put_AdminLevel(This,newVal) ) 

#define IInterfaceAccount_get_Rules(This,pVal)	\
    ( (This)->lpVtbl -> get_Rules(This,pVal) ) 

#define IInterfaceAccount_ValidatePassword(This,Password,pVal)	\
    ( (This)->lpVtbl -> ValidatePassword(This,Password,pVal) ) 

#define IInterfaceAccount_UnlockMailbox(This)	\
    ( (This)->lpVtbl -> UnlockMailbox(This) ) 

#define IInterfaceAccount_get_IMAPFolders(This,pVal)	\
    ( (This)->lpVtbl -> get_IMAPFolders(This,pVal) ) 

#define IInterfaceAccount_get_QuotaUsed(This,pVal)	\
    ( (This)->lpVtbl -> get_QuotaUsed(This,pVal) ) 

#define IInterfaceAccount_get_ForwardEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_ForwardEnabled(This,pVal) ) 

#define IInterfaceAccount_put_ForwardEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_ForwardEnabled(This,newVal) ) 

#define IInterfaceAccount_get_ForwardAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_ForwardAddress(This,pVal) ) 

#define IInterfaceAccount_put_ForwardAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_ForwardAddress(This,newVal) ) 

#define IInterfaceAccount_get_ForwardKeepOriginal(This,pVal)	\
    ( (This)->lpVtbl -> get_ForwardKeepOriginal(This,pVal) ) 

#define IInterfaceAccount_put_ForwardKeepOriginal(This,newVal)	\
    ( (This)->lpVtbl -> put_ForwardKeepOriginal(This,newVal) ) 

#define IInterfaceAccount_get_SignatureEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_SignatureEnabled(This,pVal) ) 

#define IInterfaceAccount_put_SignatureEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_SignatureEnabled(This,newVal) ) 

#define IInterfaceAccount_get_SignaturePlainText(This,pVal)	\
    ( (This)->lpVtbl -> get_SignaturePlainText(This,pVal) ) 

#define IInterfaceAccount_put_SignaturePlainText(This,newVal)	\
    ( (This)->lpVtbl -> put_SignaturePlainText(This,newVal) ) 

#define IInterfaceAccount_get_SignatureHTML(This,pVal)	\
    ( (This)->lpVtbl -> get_SignatureHTML(This,pVal) ) 

#define IInterfaceAccount_put_SignatureHTML(This,newVal)	\
    ( (This)->lpVtbl -> put_SignatureHTML(This,newVal) ) 

#define IInterfaceAccount_get_LastLogonTime(This,pVal)	\
    ( (This)->lpVtbl -> get_LastLogonTime(This,pVal) ) 

#define IInterfaceAccount_get_VacationMessageExpires(This,pVal)	\
    ( (This)->lpVtbl -> get_VacationMessageExpires(This,pVal) ) 

#define IInterfaceAccount_put_VacationMessageExpires(This,newVal)	\
    ( (This)->lpVtbl -> put_VacationMessageExpires(This,newVal) ) 

#define IInterfaceAccount_get_VacationMessageExpiresDate(This,pVal)	\
    ( (This)->lpVtbl -> get_VacationMessageExpiresDate(This,pVal) ) 

#define IInterfaceAccount_put_VacationMessageExpiresDate(This,pVal)	\
    ( (This)->lpVtbl -> put_VacationMessageExpiresDate(This,pVal) ) 

#define IInterfaceAccount_get_PersonFirstName(This,pVal)	\
    ( (This)->lpVtbl -> get_PersonFirstName(This,pVal) ) 

#define IInterfaceAccount_put_PersonFirstName(This,newVal)	\
    ( (This)->lpVtbl -> put_PersonFirstName(This,newVal) ) 

#define IInterfaceAccount_get_PersonLastName(This,pVal)	\
    ( (This)->lpVtbl -> get_PersonLastName(This,pVal) ) 

#define IInterfaceAccount_put_PersonLastName(This,newVal)	\
    ( (This)->lpVtbl -> put_PersonLastName(This,newVal) ) 

#define IInterfaceAccount_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceAccount_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDatabase_INTERFACE_DEFINED__
#define __IInterfaceDatabase_INTERFACE_DEFINED__

/* interface IInterfaceDatabase */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDatabase;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("90471F47-FE77-46C7-ADDB-F800B7ED0F66")
    IInterfaceDatabase : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RequiredVersion( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentVersion( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExecuteSQL( 
            BSTR sSQLStatement) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DatabaseType( 
            /* [retval][out] */ eDBtype *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UtilGetFileNameByMessageID( 
            /* [in] */ hyper MessageID,
            /* [retval][out] */ BSTR *Output) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RequiresUpgrade( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateInternalDatabase( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateExternalDatabase( 
            eDBtype ServerType,
            BSTR ServerName,
            long lPort,
            BSTR DatabaseName,
            BSTR Username,
            BSTR Password) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DatabaseExists( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeginTransaction( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CommitTransaction( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RollbackTransaction( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExecuteSQLScript( 
            BSTR sFilename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDefaultDatabase( 
            eDBtype ServerType,
            BSTR ServerName,
            long lPort,
            BSTR DatabaseName,
            BSTR Username,
            BSTR Password) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsConnected( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServerName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DatabaseName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExecuteSQLWithReturn( 
            BSTR sSQLStatement,
            /* [retval][out] */ long *uniqueID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnsurePrerequisites( 
            long DBVersion) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDatabaseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDatabase * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDatabase * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDatabase * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDatabase * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDatabase * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDatabase * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDatabase * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequiredVersion )( 
            IInterfaceDatabase * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentVersion )( 
            IInterfaceDatabase * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExecuteSQL )( 
            IInterfaceDatabase * This,
            BSTR sSQLStatement);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DatabaseType )( 
            IInterfaceDatabase * This,
            /* [retval][out] */ eDBtype *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UtilGetFileNameByMessageID )( 
            IInterfaceDatabase * This,
            /* [in] */ hyper MessageID,
            /* [retval][out] */ BSTR *Output);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequiresUpgrade )( 
            IInterfaceDatabase * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateInternalDatabase )( 
            IInterfaceDatabase * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateExternalDatabase )( 
            IInterfaceDatabase * This,
            eDBtype ServerType,
            BSTR ServerName,
            long lPort,
            BSTR DatabaseName,
            BSTR Username,
            BSTR Password);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DatabaseExists )( 
            IInterfaceDatabase * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeginTransaction )( 
            IInterfaceDatabase * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CommitTransaction )( 
            IInterfaceDatabase * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RollbackTransaction )( 
            IInterfaceDatabase * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExecuteSQLScript )( 
            IInterfaceDatabase * This,
            BSTR sFilename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDefaultDatabase )( 
            IInterfaceDatabase * This,
            eDBtype ServerType,
            BSTR ServerName,
            long lPort,
            BSTR DatabaseName,
            BSTR Username,
            BSTR Password);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsConnected )( 
            IInterfaceDatabase * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServerName )( 
            IInterfaceDatabase * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DatabaseName )( 
            IInterfaceDatabase * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExecuteSQLWithReturn )( 
            IInterfaceDatabase * This,
            BSTR sSQLStatement,
            /* [retval][out] */ long *uniqueID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnsurePrerequisites )( 
            IInterfaceDatabase * This,
            long DBVersion);
        
        END_INTERFACE
    } IInterfaceDatabaseVtbl;

    interface IInterfaceDatabase
    {
        CONST_VTBL struct IInterfaceDatabaseVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDatabase_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDatabase_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDatabase_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDatabase_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDatabase_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDatabase_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDatabase_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDatabase_get_RequiredVersion(This,pVal)	\
    ( (This)->lpVtbl -> get_RequiredVersion(This,pVal) ) 

#define IInterfaceDatabase_get_CurrentVersion(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentVersion(This,pVal) ) 

#define IInterfaceDatabase_ExecuteSQL(This,sSQLStatement)	\
    ( (This)->lpVtbl -> ExecuteSQL(This,sSQLStatement) ) 

#define IInterfaceDatabase_get_DatabaseType(This,pVal)	\
    ( (This)->lpVtbl -> get_DatabaseType(This,pVal) ) 

#define IInterfaceDatabase_UtilGetFileNameByMessageID(This,MessageID,Output)	\
    ( (This)->lpVtbl -> UtilGetFileNameByMessageID(This,MessageID,Output) ) 

#define IInterfaceDatabase_get_RequiresUpgrade(This,pVal)	\
    ( (This)->lpVtbl -> get_RequiresUpgrade(This,pVal) ) 

#define IInterfaceDatabase_CreateInternalDatabase(This)	\
    ( (This)->lpVtbl -> CreateInternalDatabase(This) ) 

#define IInterfaceDatabase_CreateExternalDatabase(This,ServerType,ServerName,lPort,DatabaseName,Username,Password)	\
    ( (This)->lpVtbl -> CreateExternalDatabase(This,ServerType,ServerName,lPort,DatabaseName,Username,Password) ) 

#define IInterfaceDatabase_get_DatabaseExists(This,pVal)	\
    ( (This)->lpVtbl -> get_DatabaseExists(This,pVal) ) 

#define IInterfaceDatabase_BeginTransaction(This)	\
    ( (This)->lpVtbl -> BeginTransaction(This) ) 

#define IInterfaceDatabase_CommitTransaction(This)	\
    ( (This)->lpVtbl -> CommitTransaction(This) ) 

#define IInterfaceDatabase_RollbackTransaction(This)	\
    ( (This)->lpVtbl -> RollbackTransaction(This) ) 

#define IInterfaceDatabase_ExecuteSQLScript(This,sFilename)	\
    ( (This)->lpVtbl -> ExecuteSQLScript(This,sFilename) ) 

#define IInterfaceDatabase_SetDefaultDatabase(This,ServerType,ServerName,lPort,DatabaseName,Username,Password)	\
    ( (This)->lpVtbl -> SetDefaultDatabase(This,ServerType,ServerName,lPort,DatabaseName,Username,Password) ) 

#define IInterfaceDatabase_get_IsConnected(This,pVal)	\
    ( (This)->lpVtbl -> get_IsConnected(This,pVal) ) 

#define IInterfaceDatabase_get_ServerName(This,pVal)	\
    ( (This)->lpVtbl -> get_ServerName(This,pVal) ) 

#define IInterfaceDatabase_get_DatabaseName(This,pVal)	\
    ( (This)->lpVtbl -> get_DatabaseName(This,pVal) ) 

#define IInterfaceDatabase_ExecuteSQLWithReturn(This,sSQLStatement,uniqueID)	\
    ( (This)->lpVtbl -> ExecuteSQLWithReturn(This,sSQLStatement,uniqueID) ) 

#define IInterfaceDatabase_EnsurePrerequisites(This,DBVersion)	\
    ( (This)->lpVtbl -> EnsurePrerequisites(This,DBVersion) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDatabase_INTERFACE_DEFINED__ */


#ifndef __IInterfaceMessage_INTERFACE_DEFINED__
#define __IInterfaceMessage_INTERFACE_DEFINED__

/* interface IInterfaceMessage */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceMessage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8C054031-7B42-485C-BF79-3D94A7B9605F")
    IInterfaceMessage : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ hyper *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Filename( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Subject( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Subject( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_From( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_From( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Date( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Date( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Body( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Body( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HTMLBody( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HTMLBody( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Attachments( 
            /* [retval][out] */ IInterfaceAttachments **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_To( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddRecipient( 
            /* [in] */ BSTR sName,
            /* [in] */ BSTR sAddress) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FromAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FromAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearRecipients( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CC( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Recipients( 
            /* [retval][out] */ IInterfaceRecipients **pvar) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HeaderValue( 
            /* [in] */ BSTR FieldName,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HeaderValue( 
            /* [in] */ BSTR FieldName,
            /* [in] */ BSTR FieldValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HasBodyType( 
            /* [in] */ BSTR BodyType,
            /* [retval][out] */ VARIANT_BOOL *bIsValid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EncodeFields( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EncodeFields( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flag( 
            /* [in] */ eMessageFlag iType,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Flag( 
            /* [in] */ eMessageFlag iType,
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InternalDate( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Headers( 
            /* [retval][out] */ IInterfaceMessageHeaders **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RefreshContent( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeliveryAttempt( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Charset( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Charset( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ long iDestinationFolderID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UID( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceMessageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceMessage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceMessage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceMessage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceMessage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceMessage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceMessage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceMessage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceMessage * This,
            /* [retval][out] */ hyper *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IInterfaceMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Subject )( 
            IInterfaceMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Subject )( 
            IInterfaceMessage * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_From )( 
            IInterfaceMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_From )( 
            IInterfaceMessage * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Date )( 
            IInterfaceMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Date )( 
            IInterfaceMessage * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Body )( 
            IInterfaceMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Body )( 
            IInterfaceMessage * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HTMLBody )( 
            IInterfaceMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HTMLBody )( 
            IInterfaceMessage * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Attachments )( 
            IInterfaceMessage * This,
            /* [retval][out] */ IInterfaceAttachments **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceMessage * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_To )( 
            IInterfaceMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddRecipient )( 
            IInterfaceMessage * This,
            /* [in] */ BSTR sName,
            /* [in] */ BSTR sAddress);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FromAddress )( 
            IInterfaceMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FromAddress )( 
            IInterfaceMessage * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_State )( 
            IInterfaceMessage * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IInterfaceMessage * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearRecipients )( 
            IInterfaceMessage * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CC )( 
            IInterfaceMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Recipients )( 
            IInterfaceMessage * This,
            /* [retval][out] */ IInterfaceRecipients **pvar);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HeaderValue )( 
            IInterfaceMessage * This,
            /* [in] */ BSTR FieldName,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HeaderValue )( 
            IInterfaceMessage * This,
            /* [in] */ BSTR FieldName,
            /* [in] */ BSTR FieldValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HasBodyType )( 
            IInterfaceMessage * This,
            /* [in] */ BSTR BodyType,
            /* [retval][out] */ VARIANT_BOOL *bIsValid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EncodeFields )( 
            IInterfaceMessage * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EncodeFields )( 
            IInterfaceMessage * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flag )( 
            IInterfaceMessage * This,
            /* [in] */ eMessageFlag iType,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flag )( 
            IInterfaceMessage * This,
            /* [in] */ eMessageFlag iType,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InternalDate )( 
            IInterfaceMessage * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Headers )( 
            IInterfaceMessage * This,
            /* [retval][out] */ IInterfaceMessageHeaders **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RefreshContent )( 
            IInterfaceMessage * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeliveryAttempt )( 
            IInterfaceMessage * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Charset )( 
            IInterfaceMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Charset )( 
            IInterfaceMessage * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IInterfaceMessage * This,
            /* [in] */ long iDestinationFolderID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UID )( 
            IInterfaceMessage * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } IInterfaceMessageVtbl;

    interface IInterfaceMessage
    {
        CONST_VTBL struct IInterfaceMessageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceMessage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceMessage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceMessage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceMessage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceMessage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceMessage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceMessage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceMessage_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceMessage_get_Filename(This,pVal)	\
    ( (This)->lpVtbl -> get_Filename(This,pVal) ) 

#define IInterfaceMessage_get_Subject(This,pVal)	\
    ( (This)->lpVtbl -> get_Subject(This,pVal) ) 

#define IInterfaceMessage_put_Subject(This,newVal)	\
    ( (This)->lpVtbl -> put_Subject(This,newVal) ) 

#define IInterfaceMessage_get_From(This,pVal)	\
    ( (This)->lpVtbl -> get_From(This,pVal) ) 

#define IInterfaceMessage_put_From(This,newVal)	\
    ( (This)->lpVtbl -> put_From(This,newVal) ) 

#define IInterfaceMessage_get_Date(This,pVal)	\
    ( (This)->lpVtbl -> get_Date(This,pVal) ) 

#define IInterfaceMessage_put_Date(This,newVal)	\
    ( (This)->lpVtbl -> put_Date(This,newVal) ) 

#define IInterfaceMessage_get_Body(This,pVal)	\
    ( (This)->lpVtbl -> get_Body(This,pVal) ) 

#define IInterfaceMessage_put_Body(This,newVal)	\
    ( (This)->lpVtbl -> put_Body(This,newVal) ) 

#define IInterfaceMessage_get_HTMLBody(This,pVal)	\
    ( (This)->lpVtbl -> get_HTMLBody(This,pVal) ) 

#define IInterfaceMessage_put_HTMLBody(This,newVal)	\
    ( (This)->lpVtbl -> put_HTMLBody(This,newVal) ) 

#define IInterfaceMessage_get_Attachments(This,pVal)	\
    ( (This)->lpVtbl -> get_Attachments(This,pVal) ) 

#define IInterfaceMessage_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceMessage_get_To(This,pVal)	\
    ( (This)->lpVtbl -> get_To(This,pVal) ) 

#define IInterfaceMessage_AddRecipient(This,sName,sAddress)	\
    ( (This)->lpVtbl -> AddRecipient(This,sName,sAddress) ) 

#define IInterfaceMessage_get_FromAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_FromAddress(This,pVal) ) 

#define IInterfaceMessage_put_FromAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_FromAddress(This,newVal) ) 

#define IInterfaceMessage_get_State(This,pVal)	\
    ( (This)->lpVtbl -> get_State(This,pVal) ) 

#define IInterfaceMessage_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define IInterfaceMessage_ClearRecipients(This)	\
    ( (This)->lpVtbl -> ClearRecipients(This) ) 

#define IInterfaceMessage_get_CC(This,pVal)	\
    ( (This)->lpVtbl -> get_CC(This,pVal) ) 

#define IInterfaceMessage_get_Recipients(This,pvar)	\
    ( (This)->lpVtbl -> get_Recipients(This,pvar) ) 

#define IInterfaceMessage_get_HeaderValue(This,FieldName,pVal)	\
    ( (This)->lpVtbl -> get_HeaderValue(This,FieldName,pVal) ) 

#define IInterfaceMessage_put_HeaderValue(This,FieldName,FieldValue)	\
    ( (This)->lpVtbl -> put_HeaderValue(This,FieldName,FieldValue) ) 

#define IInterfaceMessage_HasBodyType(This,BodyType,bIsValid)	\
    ( (This)->lpVtbl -> HasBodyType(This,BodyType,bIsValid) ) 

#define IInterfaceMessage_get_EncodeFields(This,pVal)	\
    ( (This)->lpVtbl -> get_EncodeFields(This,pVal) ) 

#define IInterfaceMessage_put_EncodeFields(This,newVal)	\
    ( (This)->lpVtbl -> put_EncodeFields(This,newVal) ) 

#define IInterfaceMessage_get_Flag(This,iType,pVal)	\
    ( (This)->lpVtbl -> get_Flag(This,iType,pVal) ) 

#define IInterfaceMessage_put_Flag(This,iType,pVal)	\
    ( (This)->lpVtbl -> put_Flag(This,iType,pVal) ) 

#define IInterfaceMessage_get_InternalDate(This,pVal)	\
    ( (This)->lpVtbl -> get_InternalDate(This,pVal) ) 

#define IInterfaceMessage_get_Headers(This,pVal)	\
    ( (This)->lpVtbl -> get_Headers(This,pVal) ) 

#define IInterfaceMessage_RefreshContent(This)	\
    ( (This)->lpVtbl -> RefreshContent(This) ) 

#define IInterfaceMessage_get_DeliveryAttempt(This,pVal)	\
    ( (This)->lpVtbl -> get_DeliveryAttempt(This,pVal) ) 

#define IInterfaceMessage_get_Charset(This,pVal)	\
    ( (This)->lpVtbl -> get_Charset(This,pVal) ) 

#define IInterfaceMessage_put_Charset(This,newVal)	\
    ( (This)->lpVtbl -> put_Charset(This,newVal) ) 

#define IInterfaceMessage_Copy(This,iDestinationFolderID)	\
    ( (This)->lpVtbl -> Copy(This,iDestinationFolderID) ) 

#define IInterfaceMessage_get_UID(This,pVal)	\
    ( (This)->lpVtbl -> get_UID(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceMessage_INTERFACE_DEFINED__ */


#ifndef __IInterfaceMessages_INTERFACE_DEFINED__
#define __IInterfaceMessages_INTERFACE_DEFINED__

/* interface IInterfaceMessages */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceMessages;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1259E989-465E-4B63-BB0B-4DB7F6244ACE")
    IInterfaceMessages : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceMessage **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ hyper DBID,
            /* [retval][out] */ IInterfaceMessage **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ hyper lDBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceMessage **pMessage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceMessagesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceMessages * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceMessages * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceMessages * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceMessages * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceMessages * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceMessages * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceMessages * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceMessages * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceMessage **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceMessages * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceMessages * This,
            /* [in] */ hyper DBID,
            /* [retval][out] */ IInterfaceMessage **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceMessages * This,
            /* [in] */ hyper lDBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceMessages * This,
            /* [retval][out] */ IInterfaceMessage **pMessage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IInterfaceMessages * This);
        
        END_INTERFACE
    } IInterfaceMessagesVtbl;

    interface IInterfaceMessages
    {
        CONST_VTBL struct IInterfaceMessagesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceMessages_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceMessages_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceMessages_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceMessages_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceMessages_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceMessages_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceMessages_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceMessages_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceMessages_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceMessages_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceMessages_DeleteByDBID(This,lDBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,lDBID) ) 

#define IInterfaceMessages_Add(This,pMessage)	\
    ( (This)->lpVtbl -> Add(This,pMessage) ) 

#define IInterfaceMessages_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceMessages_INTERFACE_DEFINED__ */


#ifndef __IInterfaceAliases_INTERFACE_DEFINED__
#define __IInterfaceAliases_INTERFACE_DEFINED__

/* interface IInterfaceAliases */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceAliases;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("11AA2C23-66BA-4DE0-92AB-C4F8DCC21D32")
    IInterfaceAliases : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceAlias **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ long Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceAlias **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceAlias **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByName( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ IInterfaceAlias **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceAliasesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceAliases * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceAliases * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceAliases * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceAliases * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceAliases * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceAliases * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceAliases * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceAliases * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceAlias **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceAliases * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceAliases * This,
            /* [in] */ long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceAliases * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceAliases * This,
            /* [retval][out] */ IInterfaceAlias **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceAliases * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceAlias **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceAliases * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByName )( 
            IInterfaceAliases * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IInterfaceAlias **pVal);
        
        END_INTERFACE
    } IInterfaceAliasesVtbl;

    interface IInterfaceAliases
    {
        CONST_VTBL struct IInterfaceAliasesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceAliases_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceAliases_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceAliases_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceAliases_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceAliases_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceAliases_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceAliases_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceAliases_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceAliases_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceAliases_Delete(This,Index)	\
    ( (This)->lpVtbl -> Delete(This,Index) ) 

#define IInterfaceAliases_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceAliases_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceAliases_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceAliases_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceAliases_get_ItemByName(This,Name,pVal)	\
    ( (This)->lpVtbl -> get_ItemByName(This,Name,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceAliases_INTERFACE_DEFINED__ */


#ifndef __IInterfaceUtilities_INTERFACE_DEFINED__
#define __IInterfaceUtilities_INTERFACE_DEFINED__

/* interface IInterfaceUtilities */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceUtilities;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F6BB0F43-EDEE-49A8-8166-672F3017426F")
    IInterfaceUtilities : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMailServer( 
            /* [in] */ BSTR EMailAddress,
            /* [retval][out] */ BSTR *MailServer) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsValidEmailAddress( 
            /* [in] */ BSTR EMailAddress,
            /* [retval][out] */ VARIANT_BOOL *bIsValid) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsValidDomainName( 
            /* [in] */ BSTR sDomainName,
            /* [retval][out] */ VARIANT_BOOL *bIsValid) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MD5( 
            /* [in] */ BSTR Input,
            /* [retval][out] */ BSTR *Output) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BlowfishEncrypt( 
            /* [in] */ BSTR Input,
            /* [retval][out] */ BSTR *Output) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BlowfishDecrypt( 
            /* [in] */ BSTR Input,
            /* [retval][out] */ BSTR *Output) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MakeDependent( 
            /* [in] */ BSTR OtherService) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportMessageFromFile( 
            /* [in] */ BSTR sFilename,
            /* [in] */ long iAccountID,
            /* [retval][out] */ VARIANT_BOOL *bIsSuccessful) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EmailAllAccounts( 
            /* [in] */ BSTR sRecipientWildcard,
            /* [in] */ BSTR sFromAddress,
            /* [in] */ BSTR sFromName,
            /* [in] */ BSTR sSubject,
            /* [in] */ BSTR sBody,
            /* [retval][out] */ VARIANT_BOOL *bIsSuccessful) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GenerateGUID( 
            /* [retval][out] */ BSTR *Output) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunTestSuite( 
            /* [in] */ BSTR sTestPassword) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsLocalHost( 
            /* [in] */ BSTR sHostname,
            /* [retval][out] */ VARIANT_BOOL *bIsValid) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ImportMessageFromFileToIMAPFolder( 
            /* [in] */ BSTR sFilename,
            /* [in] */ long iAccountID,
            /* [in] */ BSTR sIMAPFolder,
            /* [retval][out] */ VARIANT_BOOL *bIsSuccessful) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsStrongPassword( 
            /* [in] */ BSTR Username,
            /* [in] */ BSTR Password,
            /* [retval][out] */ VARIANT_BOOL *bIsValid) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SHA256( 
            /* [in] */ BSTR Input,
            /* [retval][out] */ BSTR *Output) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CriteriaMatch( 
            /* [in] */ BSTR MatchValue,
            /* [in] */ eRuleMatchType __MIDL__IInterfaceUtilities0000,
            /* [in] */ BSTR TestValue,
            /* [retval][out] */ VARIANT_BOOL *bMatch) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RetrieveMessageID( 
            /* [in] */ BSTR sFilename,
            /* [retval][out] */ hyper *messageID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsValidIPAddress( 
            /* [in] */ BSTR IPAddress,
            /* [retval][out] */ VARIANT_BOOL *bIsValid) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PerformMaintenance( 
            /* [in] */ eMaintenanceOperation operation) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceUtilitiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceUtilities * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceUtilities * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceUtilities * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceUtilities * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceUtilities * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceUtilities * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceUtilities * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMailServer )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR EMailAddress,
            /* [retval][out] */ BSTR *MailServer);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsValidEmailAddress )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR EMailAddress,
            /* [retval][out] */ VARIANT_BOOL *bIsValid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsValidDomainName )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR sDomainName,
            /* [retval][out] */ VARIANT_BOOL *bIsValid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MD5 )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR Input,
            /* [retval][out] */ BSTR *Output);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BlowfishEncrypt )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR Input,
            /* [retval][out] */ BSTR *Output);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BlowfishDecrypt )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR Input,
            /* [retval][out] */ BSTR *Output);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MakeDependent )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR OtherService);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportMessageFromFile )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR sFilename,
            /* [in] */ long iAccountID,
            /* [retval][out] */ VARIANT_BOOL *bIsSuccessful);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EmailAllAccounts )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR sRecipientWildcard,
            /* [in] */ BSTR sFromAddress,
            /* [in] */ BSTR sFromName,
            /* [in] */ BSTR sSubject,
            /* [in] */ BSTR sBody,
            /* [retval][out] */ VARIANT_BOOL *bIsSuccessful);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GenerateGUID )( 
            IInterfaceUtilities * This,
            /* [retval][out] */ BSTR *Output);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RunTestSuite )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR sTestPassword);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsLocalHost )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR sHostname,
            /* [retval][out] */ VARIANT_BOOL *bIsValid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ImportMessageFromFileToIMAPFolder )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR sFilename,
            /* [in] */ long iAccountID,
            /* [in] */ BSTR sIMAPFolder,
            /* [retval][out] */ VARIANT_BOOL *bIsSuccessful);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsStrongPassword )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR Username,
            /* [in] */ BSTR Password,
            /* [retval][out] */ VARIANT_BOOL *bIsValid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SHA256 )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR Input,
            /* [retval][out] */ BSTR *Output);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CriteriaMatch )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR MatchValue,
            /* [in] */ eRuleMatchType __MIDL__IInterfaceUtilities0000,
            /* [in] */ BSTR TestValue,
            /* [retval][out] */ VARIANT_BOOL *bMatch);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RetrieveMessageID )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR sFilename,
            /* [retval][out] */ hyper *messageID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsValidIPAddress )( 
            IInterfaceUtilities * This,
            /* [in] */ BSTR IPAddress,
            /* [retval][out] */ VARIANT_BOOL *bIsValid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PerformMaintenance )( 
            IInterfaceUtilities * This,
            /* [in] */ eMaintenanceOperation operation);
        
        END_INTERFACE
    } IInterfaceUtilitiesVtbl;

    interface IInterfaceUtilities
    {
        CONST_VTBL struct IInterfaceUtilitiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceUtilities_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceUtilities_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceUtilities_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceUtilities_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceUtilities_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceUtilities_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceUtilities_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceUtilities_GetMailServer(This,EMailAddress,MailServer)	\
    ( (This)->lpVtbl -> GetMailServer(This,EMailAddress,MailServer) ) 

#define IInterfaceUtilities_IsValidEmailAddress(This,EMailAddress,bIsValid)	\
    ( (This)->lpVtbl -> IsValidEmailAddress(This,EMailAddress,bIsValid) ) 

#define IInterfaceUtilities_IsValidDomainName(This,sDomainName,bIsValid)	\
    ( (This)->lpVtbl -> IsValidDomainName(This,sDomainName,bIsValid) ) 

#define IInterfaceUtilities_MD5(This,Input,Output)	\
    ( (This)->lpVtbl -> MD5(This,Input,Output) ) 

#define IInterfaceUtilities_BlowfishEncrypt(This,Input,Output)	\
    ( (This)->lpVtbl -> BlowfishEncrypt(This,Input,Output) ) 

#define IInterfaceUtilities_BlowfishDecrypt(This,Input,Output)	\
    ( (This)->lpVtbl -> BlowfishDecrypt(This,Input,Output) ) 

#define IInterfaceUtilities_MakeDependent(This,OtherService)	\
    ( (This)->lpVtbl -> MakeDependent(This,OtherService) ) 

#define IInterfaceUtilities_ImportMessageFromFile(This,sFilename,iAccountID,bIsSuccessful)	\
    ( (This)->lpVtbl -> ImportMessageFromFile(This,sFilename,iAccountID,bIsSuccessful) ) 

#define IInterfaceUtilities_EmailAllAccounts(This,sRecipientWildcard,sFromAddress,sFromName,sSubject,sBody,bIsSuccessful)	\
    ( (This)->lpVtbl -> EmailAllAccounts(This,sRecipientWildcard,sFromAddress,sFromName,sSubject,sBody,bIsSuccessful) ) 

#define IInterfaceUtilities_GenerateGUID(This,Output)	\
    ( (This)->lpVtbl -> GenerateGUID(This,Output) ) 

#define IInterfaceUtilities_RunTestSuite(This,sTestPassword)	\
    ( (This)->lpVtbl -> RunTestSuite(This,sTestPassword) ) 

#define IInterfaceUtilities_IsLocalHost(This,sHostname,bIsValid)	\
    ( (This)->lpVtbl -> IsLocalHost(This,sHostname,bIsValid) ) 

#define IInterfaceUtilities_ImportMessageFromFileToIMAPFolder(This,sFilename,iAccountID,sIMAPFolder,bIsSuccessful)	\
    ( (This)->lpVtbl -> ImportMessageFromFileToIMAPFolder(This,sFilename,iAccountID,sIMAPFolder,bIsSuccessful) ) 

#define IInterfaceUtilities_IsStrongPassword(This,Username,Password,bIsValid)	\
    ( (This)->lpVtbl -> IsStrongPassword(This,Username,Password,bIsValid) ) 

#define IInterfaceUtilities_SHA256(This,Input,Output)	\
    ( (This)->lpVtbl -> SHA256(This,Input,Output) ) 

#define IInterfaceUtilities_CriteriaMatch(This,MatchValue,__MIDL__IInterfaceUtilities0000,TestValue,bMatch)	\
    ( (This)->lpVtbl -> CriteriaMatch(This,MatchValue,__MIDL__IInterfaceUtilities0000,TestValue,bMatch) ) 

#define IInterfaceUtilities_RetrieveMessageID(This,sFilename,messageID)	\
    ( (This)->lpVtbl -> RetrieveMessageID(This,sFilename,messageID) ) 

#define IInterfaceUtilities_IsValidIPAddress(This,IPAddress,bIsValid)	\
    ( (This)->lpVtbl -> IsValidIPAddress(This,IPAddress,bIsValid) ) 

#define IInterfaceUtilities_PerformMaintenance(This,operation)	\
    ( (This)->lpVtbl -> PerformMaintenance(This,operation) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceUtilities_INTERFACE_DEFINED__ */


#ifndef __IInterfaceAlias_INTERFACE_DEFINED__
#define __IInterfaceAlias_INTERFACE_DEFINED__

/* interface IInterfaceAlias */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceAlias;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9420A3E9-ED5C-4699-98BE-0CBF3B7D3714")
    IInterfaceAlias : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Active( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DomainID( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceAliasVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceAlias * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceAlias * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceAlias * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceAlias * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceAlias * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceAlias * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceAlias * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Active )( 
            IInterfaceAlias * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Active )( 
            IInterfaceAlias * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DomainID )( 
            IInterfaceAlias * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DomainID )( 
            IInterfaceAlias * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceAlias * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceAlias * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IInterfaceAlias * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IInterfaceAlias * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IInterfaceAlias * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceAlias * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceAlias * This);
        
        END_INTERFACE
    } IInterfaceAliasVtbl;

    interface IInterfaceAlias
    {
        CONST_VTBL struct IInterfaceAliasVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceAlias_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceAlias_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceAlias_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceAlias_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceAlias_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceAlias_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceAlias_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceAlias_get_Active(This,pVal)	\
    ( (This)->lpVtbl -> get_Active(This,pVal) ) 

#define IInterfaceAlias_put_Active(This,newVal)	\
    ( (This)->lpVtbl -> put_Active(This,newVal) ) 

#define IInterfaceAlias_get_DomainID(This,pVal)	\
    ( (This)->lpVtbl -> get_DomainID(This,pVal) ) 

#define IInterfaceAlias_put_DomainID(This,newVal)	\
    ( (This)->lpVtbl -> put_DomainID(This,newVal) ) 

#define IInterfaceAlias_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceAlias_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceAlias_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IInterfaceAlias_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#define IInterfaceAlias_put_Value(This,newVal)	\
    ( (This)->lpVtbl -> put_Value(This,newVal) ) 

#define IInterfaceAlias_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IInterfaceAlias_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceAlias_INTERFACE_DEFINED__ */


#ifndef __IInterfaceAttachment_INTERFACE_DEFINED__
#define __IInterfaceAttachment_INTERFACE_DEFINED__

/* interface IInterfaceAttachment */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceAttachment;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0CD0DDFF-2D30-41BE-9845-D37EADB1A007")
    IInterfaceAttachment : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Filename( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Size( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveAs( 
            BSTR sName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceAttachmentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceAttachment * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceAttachment * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceAttachment * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceAttachment * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceAttachment * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceAttachment * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceAttachment * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IInterfaceAttachment * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size )( 
            IInterfaceAttachment * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveAs )( 
            IInterfaceAttachment * This,
            BSTR sName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceAttachment * This);
        
        END_INTERFACE
    } IInterfaceAttachmentVtbl;

    interface IInterfaceAttachment
    {
        CONST_VTBL struct IInterfaceAttachmentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceAttachment_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceAttachment_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceAttachment_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceAttachment_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceAttachment_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceAttachment_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceAttachment_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceAttachment_get_Filename(This,pVal)	\
    ( (This)->lpVtbl -> get_Filename(This,pVal) ) 

#define IInterfaceAttachment_get_Size(This,pVal)	\
    ( (This)->lpVtbl -> get_Size(This,pVal) ) 

#define IInterfaceAttachment_SaveAs(This,sName)	\
    ( (This)->lpVtbl -> SaveAs(This,sName) ) 

#define IInterfaceAttachment_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceAttachment_INTERFACE_DEFINED__ */


#ifndef __IInterfaceAttachments_INTERFACE_DEFINED__
#define __IInterfaceAttachments_INTERFACE_DEFINED__

/* interface IInterfaceAttachments */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceAttachments;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BED37911-1180-4840-A831-196C6771EF54")
    IInterfaceAttachments : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceAttachment **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR sFilename) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceAttachmentsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceAttachments * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceAttachments * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceAttachments * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceAttachments * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceAttachments * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceAttachments * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceAttachments * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceAttachments * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceAttachment **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceAttachments * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IInterfaceAttachments * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceAttachments * This,
            /* [in] */ BSTR sFilename);
        
        END_INTERFACE
    } IInterfaceAttachmentsVtbl;

    interface IInterfaceAttachments
    {
        CONST_VTBL struct IInterfaceAttachmentsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceAttachments_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceAttachments_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceAttachments_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceAttachments_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceAttachments_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceAttachments_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceAttachments_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceAttachments_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceAttachments_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceAttachments_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IInterfaceAttachments_Add(This,sFilename)	\
    ( (This)->lpVtbl -> Add(This,sFilename) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceAttachments_INTERFACE_DEFINED__ */


#ifndef __IInterfaceLogging_INTERFACE_DEFINED__
#define __IInterfaceLogging_INTERFACE_DEFINED__

/* interface IInterfaceLogging */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceLogging;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AAD8A0DF-2963-4C5B-A906-6B07B9CC0643")
    IInterfaceLogging : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogSMTP( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LogSMTP( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogPOP3( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LogPOP3( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogTCPIP( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LogTCPIP( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogApplication( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LogApplication( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Device( 
            /* [retval][out] */ eLogDevice *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Device( 
            /* [in] */ eLogDevice newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogFormat( 
            /* [retval][out] */ eLogOutputFormat *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LogFormat( 
            /* [in] */ eLogOutputFormat newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogDebug( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LogDebug( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogIMAP( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LogIMAP( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableLiveLogging( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Directory( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LiveLog( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AWStatsEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AWStatsEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaskPasswordsInLog( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaskPasswordsInLog( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentEventLog( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentErrorLog( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAwstatsLog( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentDefaultLog( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_KeepFilesOpen( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_KeepFilesOpen( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LiveLoggingEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceLoggingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceLogging * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceLogging * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceLogging * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceLogging * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceLogging * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceLogging * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceLogging * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IInterfaceLogging * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IInterfaceLogging * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogSMTP )( 
            IInterfaceLogging * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LogSMTP )( 
            IInterfaceLogging * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogPOP3 )( 
            IInterfaceLogging * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LogPOP3 )( 
            IInterfaceLogging * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogTCPIP )( 
            IInterfaceLogging * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LogTCPIP )( 
            IInterfaceLogging * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogApplication )( 
            IInterfaceLogging * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LogApplication )( 
            IInterfaceLogging * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Device )( 
            IInterfaceLogging * This,
            /* [retval][out] */ eLogDevice *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Device )( 
            IInterfaceLogging * This,
            /* [in] */ eLogDevice newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogFormat )( 
            IInterfaceLogging * This,
            /* [retval][out] */ eLogOutputFormat *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LogFormat )( 
            IInterfaceLogging * This,
            /* [in] */ eLogOutputFormat newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogDebug )( 
            IInterfaceLogging * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LogDebug )( 
            IInterfaceLogging * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogIMAP )( 
            IInterfaceLogging * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LogIMAP )( 
            IInterfaceLogging * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableLiveLogging )( 
            IInterfaceLogging * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Directory )( 
            IInterfaceLogging * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LiveLog )( 
            IInterfaceLogging * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AWStatsEnabled )( 
            IInterfaceLogging * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AWStatsEnabled )( 
            IInterfaceLogging * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaskPasswordsInLog )( 
            IInterfaceLogging * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaskPasswordsInLog )( 
            IInterfaceLogging * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentEventLog )( 
            IInterfaceLogging * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentErrorLog )( 
            IInterfaceLogging * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentAwstatsLog )( 
            IInterfaceLogging * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentDefaultLog )( 
            IInterfaceLogging * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_KeepFilesOpen )( 
            IInterfaceLogging * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_KeepFilesOpen )( 
            IInterfaceLogging * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LiveLoggingEnabled )( 
            IInterfaceLogging * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } IInterfaceLoggingVtbl;

    interface IInterfaceLogging
    {
        CONST_VTBL struct IInterfaceLoggingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceLogging_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceLogging_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceLogging_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceLogging_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceLogging_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceLogging_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceLogging_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceLogging_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define IInterfaceLogging_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define IInterfaceLogging_get_LogSMTP(This,pVal)	\
    ( (This)->lpVtbl -> get_LogSMTP(This,pVal) ) 

#define IInterfaceLogging_put_LogSMTP(This,newVal)	\
    ( (This)->lpVtbl -> put_LogSMTP(This,newVal) ) 

#define IInterfaceLogging_get_LogPOP3(This,pVal)	\
    ( (This)->lpVtbl -> get_LogPOP3(This,pVal) ) 

#define IInterfaceLogging_put_LogPOP3(This,newVal)	\
    ( (This)->lpVtbl -> put_LogPOP3(This,newVal) ) 

#define IInterfaceLogging_get_LogTCPIP(This,pVal)	\
    ( (This)->lpVtbl -> get_LogTCPIP(This,pVal) ) 

#define IInterfaceLogging_put_LogTCPIP(This,newVal)	\
    ( (This)->lpVtbl -> put_LogTCPIP(This,newVal) ) 

#define IInterfaceLogging_get_LogApplication(This,pVal)	\
    ( (This)->lpVtbl -> get_LogApplication(This,pVal) ) 

#define IInterfaceLogging_put_LogApplication(This,newVal)	\
    ( (This)->lpVtbl -> put_LogApplication(This,newVal) ) 

#define IInterfaceLogging_get_Device(This,pVal)	\
    ( (This)->lpVtbl -> get_Device(This,pVal) ) 

#define IInterfaceLogging_put_Device(This,newVal)	\
    ( (This)->lpVtbl -> put_Device(This,newVal) ) 

#define IInterfaceLogging_get_LogFormat(This,pVal)	\
    ( (This)->lpVtbl -> get_LogFormat(This,pVal) ) 

#define IInterfaceLogging_put_LogFormat(This,newVal)	\
    ( (This)->lpVtbl -> put_LogFormat(This,newVal) ) 

#define IInterfaceLogging_get_LogDebug(This,pVal)	\
    ( (This)->lpVtbl -> get_LogDebug(This,pVal) ) 

#define IInterfaceLogging_put_LogDebug(This,newVal)	\
    ( (This)->lpVtbl -> put_LogDebug(This,newVal) ) 

#define IInterfaceLogging_get_LogIMAP(This,pVal)	\
    ( (This)->lpVtbl -> get_LogIMAP(This,pVal) ) 

#define IInterfaceLogging_put_LogIMAP(This,newVal)	\
    ( (This)->lpVtbl -> put_LogIMAP(This,newVal) ) 

#define IInterfaceLogging_EnableLiveLogging(This,newVal)	\
    ( (This)->lpVtbl -> EnableLiveLogging(This,newVal) ) 

#define IInterfaceLogging_get_Directory(This,pVal)	\
    ( (This)->lpVtbl -> get_Directory(This,pVal) ) 

#define IInterfaceLogging_get_LiveLog(This,pVal)	\
    ( (This)->lpVtbl -> get_LiveLog(This,pVal) ) 

#define IInterfaceLogging_get_AWStatsEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_AWStatsEnabled(This,pVal) ) 

#define IInterfaceLogging_put_AWStatsEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_AWStatsEnabled(This,newVal) ) 

#define IInterfaceLogging_get_MaskPasswordsInLog(This,pVal)	\
    ( (This)->lpVtbl -> get_MaskPasswordsInLog(This,pVal) ) 

#define IInterfaceLogging_put_MaskPasswordsInLog(This,newVal)	\
    ( (This)->lpVtbl -> put_MaskPasswordsInLog(This,newVal) ) 

#define IInterfaceLogging_get_CurrentEventLog(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentEventLog(This,pVal) ) 

#define IInterfaceLogging_get_CurrentErrorLog(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentErrorLog(This,pVal) ) 

#define IInterfaceLogging_get_CurrentAwstatsLog(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentAwstatsLog(This,pVal) ) 

#define IInterfaceLogging_get_CurrentDefaultLog(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentDefaultLog(This,pVal) ) 

#define IInterfaceLogging_get_KeepFilesOpen(This,pVal)	\
    ( (This)->lpVtbl -> get_KeepFilesOpen(This,pVal) ) 

#define IInterfaceLogging_put_KeepFilesOpen(This,newVal)	\
    ( (This)->lpVtbl -> put_KeepFilesOpen(This,newVal) ) 

#define IInterfaceLogging_get_LiveLoggingEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_LiveLoggingEnabled(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceLogging_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDistributionLists_INTERFACE_DEFINED__
#define __IInterfaceDistributionLists_INTERFACE_DEFINED__

/* interface IInterfaceDistributionLists */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDistributionLists;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8F0E22B8-0824-42DF-9260-F8B9ABFA8C61")
    IInterfaceDistributionLists : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceDistributionList **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDistributionList **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceDistributionList **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long lDBID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByAddress( 
            /* [in] */ BSTR sAddress,
            /* [retval][out] */ IInterfaceDistributionList **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDistributionListsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDistributionLists * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDistributionLists * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDistributionLists * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDistributionLists * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDistributionLists * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDistributionLists * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDistributionLists * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceDistributionLists * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceDistributionList **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceDistributionLists * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceDistributionLists * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDistributionList **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceDistributionLists * This,
            /* [retval][out] */ IInterfaceDistributionList **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceDistributionLists * This,
            /* [in] */ long lDBID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByAddress )( 
            IInterfaceDistributionLists * This,
            /* [in] */ BSTR sAddress,
            /* [retval][out] */ IInterfaceDistributionList **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceDistributionLists * This);
        
        END_INTERFACE
    } IInterfaceDistributionListsVtbl;

    interface IInterfaceDistributionLists
    {
        CONST_VTBL struct IInterfaceDistributionListsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDistributionLists_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDistributionLists_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDistributionLists_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDistributionLists_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDistributionLists_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDistributionLists_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDistributionLists_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDistributionLists_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceDistributionLists_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceDistributionLists_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceDistributionLists_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceDistributionLists_DeleteByDBID(This,lDBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,lDBID) ) 

#define IInterfaceDistributionLists_get_ItemByAddress(This,sAddress,pVal)	\
    ( (This)->lpVtbl -> get_ItemByAddress(This,sAddress,pVal) ) 

#define IInterfaceDistributionLists_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDistributionLists_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDistributionList_INTERFACE_DEFINED__
#define __IInterfaceDistributionList_INTERFACE_DEFINED__

/* interface IInterfaceDistributionList */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDistributionList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8251393D-27D8-4DF2-8A05-949C11D42C09")
    IInterfaceDistributionList : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Active( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Recipients( 
            /* [retval][out] */ IInterfaceDistributionListRecipients **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Address( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Address( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RequireSMTPAuth( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RequireSMTPAuth( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RequireSenderAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RequireSenderAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Mode( 
            /* [retval][out] */ eDistributionListMode *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Mode( 
            /* [in] */ eDistributionListMode newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDistributionListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDistributionList * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDistributionList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDistributionList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDistributionList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDistributionList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDistributionList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDistributionList * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceDistributionList * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceDistributionList * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceDistributionList * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Active )( 
            IInterfaceDistributionList * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Active )( 
            IInterfaceDistributionList * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Recipients )( 
            IInterfaceDistributionList * This,
            /* [retval][out] */ IInterfaceDistributionListRecipients **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Address )( 
            IInterfaceDistributionList * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Address )( 
            IInterfaceDistributionList * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequireSMTPAuth )( 
            IInterfaceDistributionList * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RequireSMTPAuth )( 
            IInterfaceDistributionList * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequireSenderAddress )( 
            IInterfaceDistributionList * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RequireSenderAddress )( 
            IInterfaceDistributionList * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Mode )( 
            IInterfaceDistributionList * This,
            /* [retval][out] */ eDistributionListMode *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Mode )( 
            IInterfaceDistributionList * This,
            /* [in] */ eDistributionListMode newVal);
        
        END_INTERFACE
    } IInterfaceDistributionListVtbl;

    interface IInterfaceDistributionList
    {
        CONST_VTBL struct IInterfaceDistributionListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDistributionList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDistributionList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDistributionList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDistributionList_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDistributionList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDistributionList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDistributionList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDistributionList_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceDistributionList_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IInterfaceDistributionList_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceDistributionList_get_Active(This,pVal)	\
    ( (This)->lpVtbl -> get_Active(This,pVal) ) 

#define IInterfaceDistributionList_put_Active(This,newVal)	\
    ( (This)->lpVtbl -> put_Active(This,newVal) ) 

#define IInterfaceDistributionList_get_Recipients(This,pVal)	\
    ( (This)->lpVtbl -> get_Recipients(This,pVal) ) 

#define IInterfaceDistributionList_get_Address(This,pVal)	\
    ( (This)->lpVtbl -> get_Address(This,pVal) ) 

#define IInterfaceDistributionList_put_Address(This,newVal)	\
    ( (This)->lpVtbl -> put_Address(This,newVal) ) 

#define IInterfaceDistributionList_get_RequireSMTPAuth(This,pVal)	\
    ( (This)->lpVtbl -> get_RequireSMTPAuth(This,pVal) ) 

#define IInterfaceDistributionList_put_RequireSMTPAuth(This,newVal)	\
    ( (This)->lpVtbl -> put_RequireSMTPAuth(This,newVal) ) 

#define IInterfaceDistributionList_get_RequireSenderAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_RequireSenderAddress(This,pVal) ) 

#define IInterfaceDistributionList_put_RequireSenderAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_RequireSenderAddress(This,newVal) ) 

#define IInterfaceDistributionList_get_Mode(This,pVal)	\
    ( (This)->lpVtbl -> get_Mode(This,pVal) ) 

#define IInterfaceDistributionList_put_Mode(This,newVal)	\
    ( (This)->lpVtbl -> put_Mode(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDistributionList_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDistributionListRecipients_INTERFACE_DEFINED__
#define __IInterfaceDistributionListRecipients_INTERFACE_DEFINED__

/* interface IInterfaceDistributionListRecipients */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDistributionListRecipients;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F8759D53-9D91-47EA-A8C2-A9AF151E1FD4")
    IInterfaceDistributionListRecipients : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceDistributionListRecipient **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDistributionListRecipient **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceDistributionListRecipient **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long lDBID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDistributionListRecipientsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDistributionListRecipients * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDistributionListRecipients * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDistributionListRecipients * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDistributionListRecipients * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDistributionListRecipients * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDistributionListRecipients * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDistributionListRecipients * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceDistributionListRecipients * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceDistributionListRecipient **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceDistributionListRecipients * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceDistributionListRecipients * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDistributionListRecipient **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceDistributionListRecipients * This,
            /* [retval][out] */ IInterfaceDistributionListRecipient **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceDistributionListRecipients * This,
            /* [in] */ long lDBID);
        
        END_INTERFACE
    } IInterfaceDistributionListRecipientsVtbl;

    interface IInterfaceDistributionListRecipients
    {
        CONST_VTBL struct IInterfaceDistributionListRecipientsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDistributionListRecipients_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDistributionListRecipients_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDistributionListRecipients_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDistributionListRecipients_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDistributionListRecipients_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDistributionListRecipients_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDistributionListRecipients_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDistributionListRecipients_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceDistributionListRecipients_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceDistributionListRecipients_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceDistributionListRecipients_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceDistributionListRecipients_DeleteByDBID(This,lDBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,lDBID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDistributionListRecipients_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDistributionListRecipient_INTERFACE_DEFINED__
#define __IInterfaceDistributionListRecipient_INTERFACE_DEFINED__

/* interface IInterfaceDistributionListRecipient */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDistributionListRecipient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6DD90CB4-5E1E-45C8-9748-28A020A13E4D")
    IInterfaceDistributionListRecipient : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RecipientAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RecipientAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDistributionListRecipientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDistributionListRecipient * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDistributionListRecipient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDistributionListRecipient * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDistributionListRecipient * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDistributionListRecipient * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDistributionListRecipient * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDistributionListRecipient * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceDistributionListRecipient * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecipientAddress )( 
            IInterfaceDistributionListRecipient * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RecipientAddress )( 
            IInterfaceDistributionListRecipient * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceDistributionListRecipient * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceDistributionListRecipient * This);
        
        END_INTERFACE
    } IInterfaceDistributionListRecipientVtbl;

    interface IInterfaceDistributionListRecipient
    {
        CONST_VTBL struct IInterfaceDistributionListRecipientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDistributionListRecipient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDistributionListRecipient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDistributionListRecipient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDistributionListRecipient_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDistributionListRecipient_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDistributionListRecipient_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDistributionListRecipient_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDistributionListRecipient_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceDistributionListRecipient_get_RecipientAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_RecipientAddress(This,pVal) ) 

#define IInterfaceDistributionListRecipient_put_RecipientAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_RecipientAddress(This,newVal) ) 

#define IInterfaceDistributionListRecipient_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IInterfaceDistributionListRecipient_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDistributionListRecipient_INTERFACE_DEFINED__ */


#ifndef __IInterfaceSecurityRange_INTERFACE_DEFINED__
#define __IInterfaceSecurityRange_INTERFACE_DEFINED__

/* interface IInterfaceSecurityRange */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceSecurityRange;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3B1CB89D-9248-413D-BF2A-F000E6DB5F54")
    IInterfaceSecurityRange : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LowerIP( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LowerIP( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UpperIP( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UpperIP( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowSMTPConnections( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowSMTPConnections( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowPOP3Connections( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowPOP3Connections( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Priority( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Priority( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowIMAPConnections( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowIMAPConnections( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RequireAuthForDeliveryToLocal( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RequireAuthForDeliveryToLocal( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RequireAuthForDeliveryToRemote( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RequireAuthForDeliveryToRemote( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowDeliveryFromLocalToLocal( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowDeliveryFromLocalToLocal( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowDeliveryFromLocalToRemote( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowDeliveryFromLocalToRemote( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowDeliveryFromRemoteToLocal( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowDeliveryFromRemoteToLocal( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowDeliveryFromRemoteToRemote( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowDeliveryFromRemoteToRemote( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableSpamProtection( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableSpamProtection( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsForwardingRelay( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IsForwardingRelay( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableAntiVirus( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableAntiVirus( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Expires( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Expires( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExpiresTime( 
            /* [retval][out] */ VARIANT *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ExpiresTime( 
            /* [in] */ VARIANT pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RequireSMTPAuthLocalToLocal( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RequireSMTPAuthLocalToLocal( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RequireSMTPAuthLocalToExternal( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RequireSMTPAuthLocalToExternal( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RequireSMTPAuthExternalToLocal( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RequireSMTPAuthExternalToLocal( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RequireSMTPAuthExternalToExternal( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RequireSMTPAuthExternalToExternal( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceSecurityRangeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceSecurityRange * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceSecurityRange * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceSecurityRange * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceSecurityRange * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceSecurityRange * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceSecurityRange * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceSecurityRange * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LowerIP )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LowerIP )( 
            IInterfaceSecurityRange * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UpperIP )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UpperIP )( 
            IInterfaceSecurityRange * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowSMTPConnections )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowSMTPConnections )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowPOP3Connections )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowPOP3Connections )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Priority )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Priority )( 
            IInterfaceSecurityRange * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceSecurityRange * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowIMAPConnections )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowIMAPConnections )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IInterfaceSecurityRange * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequireAuthForDeliveryToLocal )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RequireAuthForDeliveryToLocal )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequireAuthForDeliveryToRemote )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RequireAuthForDeliveryToRemote )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowDeliveryFromLocalToLocal )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowDeliveryFromLocalToLocal )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowDeliveryFromLocalToRemote )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowDeliveryFromLocalToRemote )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowDeliveryFromRemoteToLocal )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowDeliveryFromRemoteToLocal )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllowDeliveryFromRemoteToRemote )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllowDeliveryFromRemoteToRemote )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSpamProtection )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSpamProtection )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsForwardingRelay )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IsForwardingRelay )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableAntiVirus )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableAntiVirus )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceSecurityRange * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Expires )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Expires )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExpiresTime )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ExpiresTime )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequireSMTPAuthLocalToLocal )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RequireSMTPAuthLocalToLocal )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequireSMTPAuthLocalToExternal )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RequireSMTPAuthLocalToExternal )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequireSMTPAuthExternalToLocal )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RequireSMTPAuthExternalToLocal )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RequireSMTPAuthExternalToExternal )( 
            IInterfaceSecurityRange * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RequireSMTPAuthExternalToExternal )( 
            IInterfaceSecurityRange * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } IInterfaceSecurityRangeVtbl;

    interface IInterfaceSecurityRange
    {
        CONST_VTBL struct IInterfaceSecurityRangeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceSecurityRange_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceSecurityRange_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceSecurityRange_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceSecurityRange_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceSecurityRange_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceSecurityRange_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceSecurityRange_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceSecurityRange_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceSecurityRange_get_LowerIP(This,pVal)	\
    ( (This)->lpVtbl -> get_LowerIP(This,pVal) ) 

#define IInterfaceSecurityRange_put_LowerIP(This,pVal)	\
    ( (This)->lpVtbl -> put_LowerIP(This,pVal) ) 

#define IInterfaceSecurityRange_get_UpperIP(This,pVal)	\
    ( (This)->lpVtbl -> get_UpperIP(This,pVal) ) 

#define IInterfaceSecurityRange_put_UpperIP(This,pVal)	\
    ( (This)->lpVtbl -> put_UpperIP(This,pVal) ) 

#define IInterfaceSecurityRange_get_AllowSMTPConnections(This,pVal)	\
    ( (This)->lpVtbl -> get_AllowSMTPConnections(This,pVal) ) 

#define IInterfaceSecurityRange_put_AllowSMTPConnections(This,newVal)	\
    ( (This)->lpVtbl -> put_AllowSMTPConnections(This,newVal) ) 

#define IInterfaceSecurityRange_get_AllowPOP3Connections(This,pVal)	\
    ( (This)->lpVtbl -> get_AllowPOP3Connections(This,pVal) ) 

#define IInterfaceSecurityRange_put_AllowPOP3Connections(This,newVal)	\
    ( (This)->lpVtbl -> put_AllowPOP3Connections(This,newVal) ) 

#define IInterfaceSecurityRange_get_Priority(This,pVal)	\
    ( (This)->lpVtbl -> get_Priority(This,pVal) ) 

#define IInterfaceSecurityRange_put_Priority(This,newVal)	\
    ( (This)->lpVtbl -> put_Priority(This,newVal) ) 

#define IInterfaceSecurityRange_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceSecurityRange_get_AllowIMAPConnections(This,pVal)	\
    ( (This)->lpVtbl -> get_AllowIMAPConnections(This,pVal) ) 

#define IInterfaceSecurityRange_put_AllowIMAPConnections(This,newVal)	\
    ( (This)->lpVtbl -> put_AllowIMAPConnections(This,newVal) ) 

#define IInterfaceSecurityRange_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceSecurityRange_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IInterfaceSecurityRange_get_RequireAuthForDeliveryToLocal(This,pVal)	\
    ( (This)->lpVtbl -> get_RequireAuthForDeliveryToLocal(This,pVal) ) 

#define IInterfaceSecurityRange_put_RequireAuthForDeliveryToLocal(This,newVal)	\
    ( (This)->lpVtbl -> put_RequireAuthForDeliveryToLocal(This,newVal) ) 

#define IInterfaceSecurityRange_get_RequireAuthForDeliveryToRemote(This,pVal)	\
    ( (This)->lpVtbl -> get_RequireAuthForDeliveryToRemote(This,pVal) ) 

#define IInterfaceSecurityRange_put_RequireAuthForDeliveryToRemote(This,newVal)	\
    ( (This)->lpVtbl -> put_RequireAuthForDeliveryToRemote(This,newVal) ) 

#define IInterfaceSecurityRange_get_AllowDeliveryFromLocalToLocal(This,pVal)	\
    ( (This)->lpVtbl -> get_AllowDeliveryFromLocalToLocal(This,pVal) ) 

#define IInterfaceSecurityRange_put_AllowDeliveryFromLocalToLocal(This,newVal)	\
    ( (This)->lpVtbl -> put_AllowDeliveryFromLocalToLocal(This,newVal) ) 

#define IInterfaceSecurityRange_get_AllowDeliveryFromLocalToRemote(This,pVal)	\
    ( (This)->lpVtbl -> get_AllowDeliveryFromLocalToRemote(This,pVal) ) 

#define IInterfaceSecurityRange_put_AllowDeliveryFromLocalToRemote(This,newVal)	\
    ( (This)->lpVtbl -> put_AllowDeliveryFromLocalToRemote(This,newVal) ) 

#define IInterfaceSecurityRange_get_AllowDeliveryFromRemoteToLocal(This,pVal)	\
    ( (This)->lpVtbl -> get_AllowDeliveryFromRemoteToLocal(This,pVal) ) 

#define IInterfaceSecurityRange_put_AllowDeliveryFromRemoteToLocal(This,newVal)	\
    ( (This)->lpVtbl -> put_AllowDeliveryFromRemoteToLocal(This,newVal) ) 

#define IInterfaceSecurityRange_get_AllowDeliveryFromRemoteToRemote(This,pVal)	\
    ( (This)->lpVtbl -> get_AllowDeliveryFromRemoteToRemote(This,pVal) ) 

#define IInterfaceSecurityRange_put_AllowDeliveryFromRemoteToRemote(This,newVal)	\
    ( (This)->lpVtbl -> put_AllowDeliveryFromRemoteToRemote(This,newVal) ) 

#define IInterfaceSecurityRange_get_EnableSpamProtection(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableSpamProtection(This,pVal) ) 

#define IInterfaceSecurityRange_put_EnableSpamProtection(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableSpamProtection(This,newVal) ) 

#define IInterfaceSecurityRange_get_IsForwardingRelay(This,pVal)	\
    ( (This)->lpVtbl -> get_IsForwardingRelay(This,pVal) ) 

#define IInterfaceSecurityRange_put_IsForwardingRelay(This,newVal)	\
    ( (This)->lpVtbl -> put_IsForwardingRelay(This,newVal) ) 

#define IInterfaceSecurityRange_get_EnableAntiVirus(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableAntiVirus(This,pVal) ) 

#define IInterfaceSecurityRange_put_EnableAntiVirus(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableAntiVirus(This,newVal) ) 

#define IInterfaceSecurityRange_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IInterfaceSecurityRange_get_Expires(This,pVal)	\
    ( (This)->lpVtbl -> get_Expires(This,pVal) ) 

#define IInterfaceSecurityRange_put_Expires(This,newVal)	\
    ( (This)->lpVtbl -> put_Expires(This,newVal) ) 

#define IInterfaceSecurityRange_get_ExpiresTime(This,pVal)	\
    ( (This)->lpVtbl -> get_ExpiresTime(This,pVal) ) 

#define IInterfaceSecurityRange_put_ExpiresTime(This,pVal)	\
    ( (This)->lpVtbl -> put_ExpiresTime(This,pVal) ) 

#define IInterfaceSecurityRange_get_RequireSMTPAuthLocalToLocal(This,pVal)	\
    ( (This)->lpVtbl -> get_RequireSMTPAuthLocalToLocal(This,pVal) ) 

#define IInterfaceSecurityRange_put_RequireSMTPAuthLocalToLocal(This,newVal)	\
    ( (This)->lpVtbl -> put_RequireSMTPAuthLocalToLocal(This,newVal) ) 

#define IInterfaceSecurityRange_get_RequireSMTPAuthLocalToExternal(This,pVal)	\
    ( (This)->lpVtbl -> get_RequireSMTPAuthLocalToExternal(This,pVal) ) 

#define IInterfaceSecurityRange_put_RequireSMTPAuthLocalToExternal(This,newVal)	\
    ( (This)->lpVtbl -> put_RequireSMTPAuthLocalToExternal(This,newVal) ) 

#define IInterfaceSecurityRange_get_RequireSMTPAuthExternalToLocal(This,pVal)	\
    ( (This)->lpVtbl -> get_RequireSMTPAuthExternalToLocal(This,pVal) ) 

#define IInterfaceSecurityRange_put_RequireSMTPAuthExternalToLocal(This,newVal)	\
    ( (This)->lpVtbl -> put_RequireSMTPAuthExternalToLocal(This,newVal) ) 

#define IInterfaceSecurityRange_get_RequireSMTPAuthExternalToExternal(This,pVal)	\
    ( (This)->lpVtbl -> get_RequireSMTPAuthExternalToExternal(This,pVal) ) 

#define IInterfaceSecurityRange_put_RequireSMTPAuthExternalToExternal(This,newVal)	\
    ( (This)->lpVtbl -> put_RequireSMTPAuthExternalToExternal(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceSecurityRange_INTERFACE_DEFINED__ */


#ifndef __IInterfaceSecurityRanges_INTERFACE_DEFINED__
#define __IInterfaceSecurityRanges_INTERFACE_DEFINED__

/* interface IInterfaceSecurityRanges */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceSecurityRanges;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3F0053E1-2328-452F-855D-87FF63E06BE0")
    IInterfaceSecurityRanges : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceSecurityRange **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceSecurityRange **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ long Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceSecurityRange **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByName( 
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceSecurityRange **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDefault( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceSecurityRangesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceSecurityRanges * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceSecurityRanges * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceSecurityRanges * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceSecurityRanges * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceSecurityRanges * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceSecurityRanges * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceSecurityRanges * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceSecurityRanges * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceSecurityRange **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceSecurityRanges * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceSecurityRange **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceSecurityRanges * This,
            /* [in] */ long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceSecurityRanges * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceSecurityRanges * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceSecurityRanges * This,
            /* [retval][out] */ IInterfaceSecurityRange **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceSecurityRanges * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByName )( 
            IInterfaceSecurityRanges * This,
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceSecurityRange **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDefault )( 
            IInterfaceSecurityRanges * This);
        
        END_INTERFACE
    } IInterfaceSecurityRangesVtbl;

    interface IInterfaceSecurityRanges
    {
        CONST_VTBL struct IInterfaceSecurityRangesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceSecurityRanges_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceSecurityRanges_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceSecurityRanges_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceSecurityRanges_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceSecurityRanges_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceSecurityRanges_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceSecurityRanges_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceSecurityRanges_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceSecurityRanges_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceSecurityRanges_Delete(This,Index)	\
    ( (This)->lpVtbl -> Delete(This,Index) ) 

#define IInterfaceSecurityRanges_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceSecurityRanges_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceSecurityRanges_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceSecurityRanges_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceSecurityRanges_get_ItemByName(This,sName,pVal)	\
    ( (This)->lpVtbl -> get_ItemByName(This,sName,pVal) ) 

#define IInterfaceSecurityRanges_SetDefault(This)	\
    ( (This)->lpVtbl -> SetDefault(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceSecurityRanges_INTERFACE_DEFINED__ */


#ifndef __IInterfaceAntiVirus_INTERFACE_DEFINED__
#define __IInterfaceAntiVirus_INTERFACE_DEFINED__

/* interface IInterfaceAntiVirus */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceAntiVirus;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("952EE84F-C1D4-4869-8B86-76A3BA8F39FA")
    IInterfaceAntiVirus : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClamWinEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ClamWinEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClamWinExecutable( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ClamWinExecutable( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClamWinDBFolder( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ClamWinDBFolder( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Action( 
            /* [retval][out] */ eAntivirusAction *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Action( 
            /* [in] */ eAntivirusAction newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NotifyReceiver( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NotifyReceiver( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NotifySender( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NotifySender( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomScannerEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomScannerEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomScannerExecutable( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomScannerExecutable( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CustomScannerReturnValue( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CustomScannerReturnValue( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaximumMessageSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaximumMessageSize( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockedAttachments( 
            /* [retval][out] */ IInterfaceBlockedAttachments **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableAttachmentBlocking( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableAttachmentBlocking( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClamAVEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ClamAVEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClamAVHost( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ClamAVHost( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ClamAVPort( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ClamAVPort( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TestCustomerScanner( 
            /* [in] */ BSTR customExecutable,
            long virusReturnCode,
            /* [out] */ BSTR *ResultText,
            /* [retval][out] */ VARIANT_BOOL *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TestClamWinScanner( 
            /* [in] */ BSTR clamWinExecutable,
            BSTR clamWinDatabase,
            /* [out] */ BSTR *ResultText,
            /* [retval][out] */ VARIANT_BOOL *pResult) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TestClamAVScanner( 
            /* [in] */ BSTR ClamAVHostName,
            long ClamAVPort,
            /* [out] */ BSTR *ResultText,
            /* [retval][out] */ VARIANT_BOOL *pResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceAntiVirusVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceAntiVirus * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceAntiVirus * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceAntiVirus * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceAntiVirus * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceAntiVirus * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceAntiVirus * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceAntiVirus * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClamWinEnabled )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClamWinEnabled )( 
            IInterfaceAntiVirus * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClamWinExecutable )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClamWinExecutable )( 
            IInterfaceAntiVirus * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClamWinDBFolder )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClamWinDBFolder )( 
            IInterfaceAntiVirus * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Action )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ eAntivirusAction *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Action )( 
            IInterfaceAntiVirus * This,
            /* [in] */ eAntivirusAction newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NotifyReceiver )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NotifyReceiver )( 
            IInterfaceAntiVirus * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NotifySender )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NotifySender )( 
            IInterfaceAntiVirus * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomScannerEnabled )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomScannerEnabled )( 
            IInterfaceAntiVirus * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomScannerExecutable )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomScannerExecutable )( 
            IInterfaceAntiVirus * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CustomScannerReturnValue )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CustomScannerReturnValue )( 
            IInterfaceAntiVirus * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaximumMessageSize )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaximumMessageSize )( 
            IInterfaceAntiVirus * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockedAttachments )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ IInterfaceBlockedAttachments **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableAttachmentBlocking )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableAttachmentBlocking )( 
            IInterfaceAntiVirus * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClamAVEnabled )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClamAVEnabled )( 
            IInterfaceAntiVirus * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClamAVHost )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClamAVHost )( 
            IInterfaceAntiVirus * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ClamAVPort )( 
            IInterfaceAntiVirus * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ClamAVPort )( 
            IInterfaceAntiVirus * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TestCustomerScanner )( 
            IInterfaceAntiVirus * This,
            /* [in] */ BSTR customExecutable,
            long virusReturnCode,
            /* [out] */ BSTR *ResultText,
            /* [retval][out] */ VARIANT_BOOL *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TestClamWinScanner )( 
            IInterfaceAntiVirus * This,
            /* [in] */ BSTR clamWinExecutable,
            BSTR clamWinDatabase,
            /* [out] */ BSTR *ResultText,
            /* [retval][out] */ VARIANT_BOOL *pResult);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TestClamAVScanner )( 
            IInterfaceAntiVirus * This,
            /* [in] */ BSTR ClamAVHostName,
            long ClamAVPort,
            /* [out] */ BSTR *ResultText,
            /* [retval][out] */ VARIANT_BOOL *pResult);
        
        END_INTERFACE
    } IInterfaceAntiVirusVtbl;

    interface IInterfaceAntiVirus
    {
        CONST_VTBL struct IInterfaceAntiVirusVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceAntiVirus_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceAntiVirus_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceAntiVirus_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceAntiVirus_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceAntiVirus_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceAntiVirus_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceAntiVirus_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceAntiVirus_get_ClamWinEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_ClamWinEnabled(This,pVal) ) 

#define IInterfaceAntiVirus_put_ClamWinEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_ClamWinEnabled(This,newVal) ) 

#define IInterfaceAntiVirus_get_ClamWinExecutable(This,pVal)	\
    ( (This)->lpVtbl -> get_ClamWinExecutable(This,pVal) ) 

#define IInterfaceAntiVirus_put_ClamWinExecutable(This,newVal)	\
    ( (This)->lpVtbl -> put_ClamWinExecutable(This,newVal) ) 

#define IInterfaceAntiVirus_get_ClamWinDBFolder(This,pVal)	\
    ( (This)->lpVtbl -> get_ClamWinDBFolder(This,pVal) ) 

#define IInterfaceAntiVirus_put_ClamWinDBFolder(This,newVal)	\
    ( (This)->lpVtbl -> put_ClamWinDBFolder(This,newVal) ) 

#define IInterfaceAntiVirus_get_Action(This,pVal)	\
    ( (This)->lpVtbl -> get_Action(This,pVal) ) 

#define IInterfaceAntiVirus_put_Action(This,newVal)	\
    ( (This)->lpVtbl -> put_Action(This,newVal) ) 

#define IInterfaceAntiVirus_get_NotifyReceiver(This,pVal)	\
    ( (This)->lpVtbl -> get_NotifyReceiver(This,pVal) ) 

#define IInterfaceAntiVirus_put_NotifyReceiver(This,newVal)	\
    ( (This)->lpVtbl -> put_NotifyReceiver(This,newVal) ) 

#define IInterfaceAntiVirus_get_NotifySender(This,pVal)	\
    ( (This)->lpVtbl -> get_NotifySender(This,pVal) ) 

#define IInterfaceAntiVirus_put_NotifySender(This,newVal)	\
    ( (This)->lpVtbl -> put_NotifySender(This,newVal) ) 

#define IInterfaceAntiVirus_get_CustomScannerEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomScannerEnabled(This,pVal) ) 

#define IInterfaceAntiVirus_put_CustomScannerEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomScannerEnabled(This,newVal) ) 

#define IInterfaceAntiVirus_get_CustomScannerExecutable(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomScannerExecutable(This,pVal) ) 

#define IInterfaceAntiVirus_put_CustomScannerExecutable(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomScannerExecutable(This,newVal) ) 

#define IInterfaceAntiVirus_get_CustomScannerReturnValue(This,pVal)	\
    ( (This)->lpVtbl -> get_CustomScannerReturnValue(This,pVal) ) 

#define IInterfaceAntiVirus_put_CustomScannerReturnValue(This,newVal)	\
    ( (This)->lpVtbl -> put_CustomScannerReturnValue(This,newVal) ) 

#define IInterfaceAntiVirus_get_MaximumMessageSize(This,pVal)	\
    ( (This)->lpVtbl -> get_MaximumMessageSize(This,pVal) ) 

#define IInterfaceAntiVirus_put_MaximumMessageSize(This,newVal)	\
    ( (This)->lpVtbl -> put_MaximumMessageSize(This,newVal) ) 

#define IInterfaceAntiVirus_get_BlockedAttachments(This,pVal)	\
    ( (This)->lpVtbl -> get_BlockedAttachments(This,pVal) ) 

#define IInterfaceAntiVirus_get_EnableAttachmentBlocking(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableAttachmentBlocking(This,pVal) ) 

#define IInterfaceAntiVirus_put_EnableAttachmentBlocking(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableAttachmentBlocking(This,newVal) ) 

#define IInterfaceAntiVirus_get_ClamAVEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_ClamAVEnabled(This,pVal) ) 

#define IInterfaceAntiVirus_put_ClamAVEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_ClamAVEnabled(This,newVal) ) 

#define IInterfaceAntiVirus_get_ClamAVHost(This,pVal)	\
    ( (This)->lpVtbl -> get_ClamAVHost(This,pVal) ) 

#define IInterfaceAntiVirus_put_ClamAVHost(This,newVal)	\
    ( (This)->lpVtbl -> put_ClamAVHost(This,newVal) ) 

#define IInterfaceAntiVirus_get_ClamAVPort(This,pVal)	\
    ( (This)->lpVtbl -> get_ClamAVPort(This,pVal) ) 

#define IInterfaceAntiVirus_put_ClamAVPort(This,newVal)	\
    ( (This)->lpVtbl -> put_ClamAVPort(This,newVal) ) 

#define IInterfaceAntiVirus_TestCustomerScanner(This,customExecutable,virusReturnCode,ResultText,pResult)	\
    ( (This)->lpVtbl -> TestCustomerScanner(This,customExecutable,virusReturnCode,ResultText,pResult) ) 

#define IInterfaceAntiVirus_TestClamWinScanner(This,clamWinExecutable,clamWinDatabase,ResultText,pResult)	\
    ( (This)->lpVtbl -> TestClamWinScanner(This,clamWinExecutable,clamWinDatabase,ResultText,pResult) ) 

#define IInterfaceAntiVirus_TestClamAVScanner(This,ClamAVHostName,ClamAVPort,ResultText,pResult)	\
    ( (This)->lpVtbl -> TestClamAVScanner(This,ClamAVHostName,ClamAVPort,ResultText,pResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceAntiVirus_INTERFACE_DEFINED__ */


#ifndef __IInterfaceRoute_INTERFACE_DEFINED__
#define __IInterfaceRoute_INTERFACE_DEFINED__

/* interface IInterfaceRoute */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceRoute;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F78FA851-D3D3-4A28-AFCC-A471C00781D3")
    IInterfaceRoute : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DomainName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TargetSMTPHost( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TargetSMTPHost( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TargetSMTPPort( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TargetSMTPPort( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NumberOfTries( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NumberOfTries( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinutesBetweenTry( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MinutesBetweenTry( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllAddresses( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllAddresses( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Addresses( 
            /* [retval][out] */ IInterfaceRouteAddresses **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RelayerRequiresAuth( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RelayerRequiresAuth( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RelayerAuthUsername( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RelayerAuthUsername( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRelayerAuthPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TreatSecurityAsLocalDomain( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TreatSecurityAsLocalDomain( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseSSL( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseSSL( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TreatSenderAsLocalDomain( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TreatSenderAsLocalDomain( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TreatRecipientAsLocalDomain( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TreatRecipientAsLocalDomain( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceRouteVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceRoute * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceRoute * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceRoute * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceRoute * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceRoute * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceRoute * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceRoute * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceRoute * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DomainName )( 
            IInterfaceRoute * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DomainName )( 
            IInterfaceRoute * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TargetSMTPHost )( 
            IInterfaceRoute * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TargetSMTPHost )( 
            IInterfaceRoute * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TargetSMTPPort )( 
            IInterfaceRoute * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TargetSMTPPort )( 
            IInterfaceRoute * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumberOfTries )( 
            IInterfaceRoute * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NumberOfTries )( 
            IInterfaceRoute * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinutesBetweenTry )( 
            IInterfaceRoute * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinutesBetweenTry )( 
            IInterfaceRoute * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AllAddresses )( 
            IInterfaceRoute * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AllAddresses )( 
            IInterfaceRoute * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Addresses )( 
            IInterfaceRoute * This,
            /* [retval][out] */ IInterfaceRouteAddresses **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RelayerRequiresAuth )( 
            IInterfaceRoute * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RelayerRequiresAuth )( 
            IInterfaceRoute * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RelayerAuthUsername )( 
            IInterfaceRoute * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RelayerAuthUsername )( 
            IInterfaceRoute * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetRelayerAuthPassword )( 
            IInterfaceRoute * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TreatSecurityAsLocalDomain )( 
            IInterfaceRoute * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TreatSecurityAsLocalDomain )( 
            IInterfaceRoute * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceRoute * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseSSL )( 
            IInterfaceRoute * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseSSL )( 
            IInterfaceRoute * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IInterfaceRoute * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            IInterfaceRoute * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceRoute * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TreatSenderAsLocalDomain )( 
            IInterfaceRoute * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TreatSenderAsLocalDomain )( 
            IInterfaceRoute * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TreatRecipientAsLocalDomain )( 
            IInterfaceRoute * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TreatRecipientAsLocalDomain )( 
            IInterfaceRoute * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } IInterfaceRouteVtbl;

    interface IInterfaceRoute
    {
        CONST_VTBL struct IInterfaceRouteVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceRoute_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceRoute_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceRoute_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceRoute_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceRoute_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceRoute_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceRoute_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceRoute_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceRoute_get_DomainName(This,pVal)	\
    ( (This)->lpVtbl -> get_DomainName(This,pVal) ) 

#define IInterfaceRoute_put_DomainName(This,newVal)	\
    ( (This)->lpVtbl -> put_DomainName(This,newVal) ) 

#define IInterfaceRoute_get_TargetSMTPHost(This,pVal)	\
    ( (This)->lpVtbl -> get_TargetSMTPHost(This,pVal) ) 

#define IInterfaceRoute_put_TargetSMTPHost(This,newVal)	\
    ( (This)->lpVtbl -> put_TargetSMTPHost(This,newVal) ) 

#define IInterfaceRoute_get_TargetSMTPPort(This,pVal)	\
    ( (This)->lpVtbl -> get_TargetSMTPPort(This,pVal) ) 

#define IInterfaceRoute_put_TargetSMTPPort(This,newVal)	\
    ( (This)->lpVtbl -> put_TargetSMTPPort(This,newVal) ) 

#define IInterfaceRoute_get_NumberOfTries(This,pVal)	\
    ( (This)->lpVtbl -> get_NumberOfTries(This,pVal) ) 

#define IInterfaceRoute_put_NumberOfTries(This,newVal)	\
    ( (This)->lpVtbl -> put_NumberOfTries(This,newVal) ) 

#define IInterfaceRoute_get_MinutesBetweenTry(This,pVal)	\
    ( (This)->lpVtbl -> get_MinutesBetweenTry(This,pVal) ) 

#define IInterfaceRoute_put_MinutesBetweenTry(This,newVal)	\
    ( (This)->lpVtbl -> put_MinutesBetweenTry(This,newVal) ) 

#define IInterfaceRoute_get_AllAddresses(This,pVal)	\
    ( (This)->lpVtbl -> get_AllAddresses(This,pVal) ) 

#define IInterfaceRoute_put_AllAddresses(This,newVal)	\
    ( (This)->lpVtbl -> put_AllAddresses(This,newVal) ) 

#define IInterfaceRoute_get_Addresses(This,pVal)	\
    ( (This)->lpVtbl -> get_Addresses(This,pVal) ) 

#define IInterfaceRoute_get_RelayerRequiresAuth(This,pVal)	\
    ( (This)->lpVtbl -> get_RelayerRequiresAuth(This,pVal) ) 

#define IInterfaceRoute_put_RelayerRequiresAuth(This,newVal)	\
    ( (This)->lpVtbl -> put_RelayerRequiresAuth(This,newVal) ) 

#define IInterfaceRoute_get_RelayerAuthUsername(This,pVal)	\
    ( (This)->lpVtbl -> get_RelayerAuthUsername(This,pVal) ) 

#define IInterfaceRoute_put_RelayerAuthUsername(This,newVal)	\
    ( (This)->lpVtbl -> put_RelayerAuthUsername(This,newVal) ) 

#define IInterfaceRoute_SetRelayerAuthPassword(This,newVal)	\
    ( (This)->lpVtbl -> SetRelayerAuthPassword(This,newVal) ) 

#define IInterfaceRoute_get_TreatSecurityAsLocalDomain(This,pVal)	\
    ( (This)->lpVtbl -> get_TreatSecurityAsLocalDomain(This,pVal) ) 

#define IInterfaceRoute_put_TreatSecurityAsLocalDomain(This,newVal)	\
    ( (This)->lpVtbl -> put_TreatSecurityAsLocalDomain(This,newVal) ) 

#define IInterfaceRoute_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceRoute_get_UseSSL(This,pVal)	\
    ( (This)->lpVtbl -> get_UseSSL(This,pVal) ) 

#define IInterfaceRoute_put_UseSSL(This,newVal)	\
    ( (This)->lpVtbl -> put_UseSSL(This,newVal) ) 

#define IInterfaceRoute_get_Description(This,pVal)	\
    ( (This)->lpVtbl -> get_Description(This,pVal) ) 

#define IInterfaceRoute_put_Description(This,newVal)	\
    ( (This)->lpVtbl -> put_Description(This,newVal) ) 

#define IInterfaceRoute_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IInterfaceRoute_get_TreatSenderAsLocalDomain(This,pVal)	\
    ( (This)->lpVtbl -> get_TreatSenderAsLocalDomain(This,pVal) ) 

#define IInterfaceRoute_put_TreatSenderAsLocalDomain(This,newVal)	\
    ( (This)->lpVtbl -> put_TreatSenderAsLocalDomain(This,newVal) ) 

#define IInterfaceRoute_get_TreatRecipientAsLocalDomain(This,pVal)	\
    ( (This)->lpVtbl -> get_TreatRecipientAsLocalDomain(This,pVal) ) 

#define IInterfaceRoute_put_TreatRecipientAsLocalDomain(This,newVal)	\
    ( (This)->lpVtbl -> put_TreatRecipientAsLocalDomain(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceRoute_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDNSBlackLists_INTERFACE_DEFINED__
#define __IInterfaceDNSBlackLists_INTERFACE_DEFINED__

/* interface IInterfaceDNSBlackLists */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDNSBlackLists;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6B87D71F-93B7-4163-AA89-DA999A5A7239")
    IInterfaceDNSBlackLists : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceDNSBlackList **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceDNSBlackList **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDNSBlackList **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDNSHost( 
            /* [in] */ BSTR sDNSHost,
            /* [retval][out] */ IInterfaceDNSBlackList **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDNSBlackListsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDNSBlackLists * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDNSBlackLists * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDNSBlackLists * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDNSBlackLists * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDNSBlackLists * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDNSBlackLists * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDNSBlackLists * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceDNSBlackLists * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceDNSBlackList **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceDNSBlackLists * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceDNSBlackLists * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceDNSBlackLists * This,
            /* [retval][out] */ IInterfaceDNSBlackList **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceDNSBlackLists * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDNSBlackList **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceDNSBlackLists * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDNSHost )( 
            IInterfaceDNSBlackLists * This,
            /* [in] */ BSTR sDNSHost,
            /* [retval][out] */ IInterfaceDNSBlackList **pVal);
        
        END_INTERFACE
    } IInterfaceDNSBlackListsVtbl;

    interface IInterfaceDNSBlackLists
    {
        CONST_VTBL struct IInterfaceDNSBlackListsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDNSBlackLists_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDNSBlackLists_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDNSBlackLists_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDNSBlackLists_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDNSBlackLists_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDNSBlackLists_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDNSBlackLists_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDNSBlackLists_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceDNSBlackLists_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceDNSBlackLists_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceDNSBlackLists_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceDNSBlackLists_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceDNSBlackLists_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceDNSBlackLists_get_ItemByDNSHost(This,sDNSHost,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDNSHost(This,sDNSHost,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDNSBlackLists_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDNSBlackList_INTERFACE_DEFINED__
#define __IInterfaceDNSBlackList_INTERFACE_DEFINED__

/* interface IInterfaceDNSBlackList */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDNSBlackList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E011153-63D9-4B86-BA97-E55D152B221D")
    IInterfaceDNSBlackList : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Active( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DNSHost( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DNSHost( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RejectMessage( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RejectMessage( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExpectedResult( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ExpectedResult( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Score( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Score( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDNSBlackListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDNSBlackList * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDNSBlackList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDNSBlackList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDNSBlackList * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDNSBlackList * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDNSBlackList * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDNSBlackList * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Active )( 
            IInterfaceDNSBlackList * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Active )( 
            IInterfaceDNSBlackList * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceDNSBlackList * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DNSHost )( 
            IInterfaceDNSBlackList * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DNSHost )( 
            IInterfaceDNSBlackList * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RejectMessage )( 
            IInterfaceDNSBlackList * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RejectMessage )( 
            IInterfaceDNSBlackList * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExpectedResult )( 
            IInterfaceDNSBlackList * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ExpectedResult )( 
            IInterfaceDNSBlackList * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceDNSBlackList * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Score )( 
            IInterfaceDNSBlackList * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Score )( 
            IInterfaceDNSBlackList * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceDNSBlackList * This);
        
        END_INTERFACE
    } IInterfaceDNSBlackListVtbl;

    interface IInterfaceDNSBlackList
    {
        CONST_VTBL struct IInterfaceDNSBlackListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDNSBlackList_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDNSBlackList_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDNSBlackList_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDNSBlackList_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDNSBlackList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDNSBlackList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDNSBlackList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDNSBlackList_get_Active(This,pVal)	\
    ( (This)->lpVtbl -> get_Active(This,pVal) ) 

#define IInterfaceDNSBlackList_put_Active(This,newVal)	\
    ( (This)->lpVtbl -> put_Active(This,newVal) ) 

#define IInterfaceDNSBlackList_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceDNSBlackList_get_DNSHost(This,pVal)	\
    ( (This)->lpVtbl -> get_DNSHost(This,pVal) ) 

#define IInterfaceDNSBlackList_put_DNSHost(This,newVal)	\
    ( (This)->lpVtbl -> put_DNSHost(This,newVal) ) 

#define IInterfaceDNSBlackList_get_RejectMessage(This,pVal)	\
    ( (This)->lpVtbl -> get_RejectMessage(This,pVal) ) 

#define IInterfaceDNSBlackList_put_RejectMessage(This,newVal)	\
    ( (This)->lpVtbl -> put_RejectMessage(This,newVal) ) 

#define IInterfaceDNSBlackList_get_ExpectedResult(This,pVal)	\
    ( (This)->lpVtbl -> get_ExpectedResult(This,pVal) ) 

#define IInterfaceDNSBlackList_put_ExpectedResult(This,newVal)	\
    ( (This)->lpVtbl -> put_ExpectedResult(This,newVal) ) 

#define IInterfaceDNSBlackList_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceDNSBlackList_get_Score(This,pVal)	\
    ( (This)->lpVtbl -> get_Score(This,pVal) ) 

#define IInterfaceDNSBlackList_put_Score(This,newVal)	\
    ( (This)->lpVtbl -> put_Score(This,newVal) ) 

#define IInterfaceDNSBlackList_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDNSBlackList_INTERFACE_DEFINED__ */


#ifndef __IInterfaceApplication_INTERFACE_DEFINED__
#define __IInterfaceApplication_INTERFACE_DEFINED__

/* interface IInterfaceApplication */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceApplication;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C1A3EF1-115F-4029-BB33-D9CCA4BB0DE8")
    IInterfaceApplication : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Settings( 
            /* [retval][out] */ IInterfaceSettings **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Domains( 
            /* [retval][out] */ IInterfaceDomains **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServerState( 
            /* [retval][out] */ eServerState *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Database( 
            /* [retval][out] */ IInterfaceDatabase **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Utilities( 
            /* [retval][out] */ IInterfaceUtilities **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SubmitEMail( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Status( 
            /* [retval][out] */ IInterfaceStatus **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_InitializationFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reinitialize( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Rules( 
            /* [retval][out] */ IInterfaceRules **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BackupManager( 
            /* [retval][out] */ IInterfaceBackupManager **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GlobalObjects( 
            /* [retval][out] */ IInterfaceGlobalObjects **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Authenticate( 
            /* [in] */ BSTR Username,
            /* [in] */ BSTR Password,
            /* [retval][out] */ IInterfaceAccount **pAccount) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Links( 
            /* [retval][out] */ IInterfaceLinks **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Diagnostics( 
            /* [retval][out] */ IInterfaceDiagnostics **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceApplicationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceApplication * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceApplication * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceApplication * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceApplication * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceApplication * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceApplication * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceApplication * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Start )( 
            IInterfaceApplication * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IInterfaceApplication * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Settings )( 
            IInterfaceApplication * This,
            /* [retval][out] */ IInterfaceSettings **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Domains )( 
            IInterfaceApplication * This,
            /* [retval][out] */ IInterfaceDomains **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServerState )( 
            IInterfaceApplication * This,
            /* [retval][out] */ eServerState *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Database )( 
            IInterfaceApplication * This,
            /* [retval][out] */ IInterfaceDatabase **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Utilities )( 
            IInterfaceApplication * This,
            /* [retval][out] */ IInterfaceUtilities **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SubmitEMail )( 
            IInterfaceApplication * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Status )( 
            IInterfaceApplication * This,
            /* [retval][out] */ IInterfaceStatus **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            IInterfaceApplication * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IInterfaceApplication * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_InitializationFile )( 
            IInterfaceApplication * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reinitialize )( 
            IInterfaceApplication * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Rules )( 
            IInterfaceApplication * This,
            /* [retval][out] */ IInterfaceRules **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackupManager )( 
            IInterfaceApplication * This,
            /* [retval][out] */ IInterfaceBackupManager **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GlobalObjects )( 
            IInterfaceApplication * This,
            /* [retval][out] */ IInterfaceGlobalObjects **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Authenticate )( 
            IInterfaceApplication * This,
            /* [in] */ BSTR Username,
            /* [in] */ BSTR Password,
            /* [retval][out] */ IInterfaceAccount **pAccount);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Links )( 
            IInterfaceApplication * This,
            /* [retval][out] */ IInterfaceLinks **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Diagnostics )( 
            IInterfaceApplication * This,
            /* [retval][out] */ IInterfaceDiagnostics **pVal);
        
        END_INTERFACE
    } IInterfaceApplicationVtbl;

    interface IInterfaceApplication
    {
        CONST_VTBL struct IInterfaceApplicationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceApplication_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceApplication_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceApplication_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceApplication_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceApplication_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceApplication_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceApplication_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceApplication_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IInterfaceApplication_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IInterfaceApplication_get_Settings(This,pVal)	\
    ( (This)->lpVtbl -> get_Settings(This,pVal) ) 

#define IInterfaceApplication_get_Domains(This,pVal)	\
    ( (This)->lpVtbl -> get_Domains(This,pVal) ) 

#define IInterfaceApplication_get_ServerState(This,pVal)	\
    ( (This)->lpVtbl -> get_ServerState(This,pVal) ) 

#define IInterfaceApplication_get_Database(This,pVal)	\
    ( (This)->lpVtbl -> get_Database(This,pVal) ) 

#define IInterfaceApplication_get_Utilities(This,pVal)	\
    ( (This)->lpVtbl -> get_Utilities(This,pVal) ) 

#define IInterfaceApplication_SubmitEMail(This)	\
    ( (This)->lpVtbl -> SubmitEMail(This) ) 

#define IInterfaceApplication_get_Status(This,pVal)	\
    ( (This)->lpVtbl -> get_Status(This,pVal) ) 

#define IInterfaceApplication_get_Version(This,pVal)	\
    ( (This)->lpVtbl -> get_Version(This,pVal) ) 

#define IInterfaceApplication_Connect(This)	\
    ( (This)->lpVtbl -> Connect(This) ) 

#define IInterfaceApplication_get_InitializationFile(This,pVal)	\
    ( (This)->lpVtbl -> get_InitializationFile(This,pVal) ) 

#define IInterfaceApplication_Reinitialize(This)	\
    ( (This)->lpVtbl -> Reinitialize(This) ) 

#define IInterfaceApplication_get_Rules(This,pVal)	\
    ( (This)->lpVtbl -> get_Rules(This,pVal) ) 

#define IInterfaceApplication_get_BackupManager(This,pVal)	\
    ( (This)->lpVtbl -> get_BackupManager(This,pVal) ) 

#define IInterfaceApplication_get_GlobalObjects(This,pVal)	\
    ( (This)->lpVtbl -> get_GlobalObjects(This,pVal) ) 

#define IInterfaceApplication_Authenticate(This,Username,Password,pAccount)	\
    ( (This)->lpVtbl -> Authenticate(This,Username,Password,pAccount) ) 

#define IInterfaceApplication_get_Links(This,pVal)	\
    ( (This)->lpVtbl -> get_Links(This,pVal) ) 

#define IInterfaceApplication_get_Diagnostics(This,pVal)	\
    ( (This)->lpVtbl -> get_Diagnostics(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceApplication_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDomains_INTERFACE_DEFINED__
#define __IInterfaceDomains_INTERFACE_DEFINED__

/* interface IInterfaceDomains */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDomains;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2CDFD68F-62F2-49CF-A14A-505E7F68EE9C")
    IInterfaceDomains : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceDomain **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceDomain **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByName( 
            /* [in] */ BSTR ItemName,
            /* [retval][out] */ IInterfaceDomain **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDomain **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Names( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDomainsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDomains * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDomains * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDomains * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDomains * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDomains * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDomains * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDomains * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceDomains * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceDomain **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceDomains * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceDomains * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceDomains * This,
            /* [retval][out] */ IInterfaceDomain **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByName )( 
            IInterfaceDomains * This,
            /* [in] */ BSTR ItemName,
            /* [retval][out] */ IInterfaceDomain **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceDomains * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDomain **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Names )( 
            IInterfaceDomains * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceDomains * This,
            /* [in] */ long DBID);
        
        END_INTERFACE
    } IInterfaceDomainsVtbl;

    interface IInterfaceDomains
    {
        CONST_VTBL struct IInterfaceDomainsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDomains_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDomains_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDomains_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDomains_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDomains_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDomains_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDomains_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDomains_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceDomains_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceDomains_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceDomains_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceDomains_get_ItemByName(This,ItemName,pVal)	\
    ( (This)->lpVtbl -> get_ItemByName(This,ItemName,pVal) ) 

#define IInterfaceDomains_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceDomains_get_Names(This,pVal)	\
    ( (This)->lpVtbl -> get_Names(This,pVal) ) 

#define IInterfaceDomains_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDomains_INTERFACE_DEFINED__ */


#ifndef __IInterfaceRoutes_INTERFACE_DEFINED__
#define __IInterfaceRoutes_INTERFACE_DEFINED__

/* interface IInterfaceRoutes */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceRoutes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("111F318A-C087-4091-BD1F-4226230EE513")
    IInterfaceRoutes : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceRoute **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceRoute **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByName( 
            /* [in] */ BSTR ItemName,
            /* [retval][out] */ IInterfaceRoute **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceRoute **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceRoutesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceRoutes * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceRoutes * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceRoutes * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceRoutes * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceRoutes * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceRoutes * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceRoutes * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceRoutes * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceRoute **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceRoutes * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceRoutes * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceRoutes * This,
            /* [retval][out] */ IInterfaceRoute **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByName )( 
            IInterfaceRoutes * This,
            /* [in] */ BSTR ItemName,
            /* [retval][out] */ IInterfaceRoute **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceRoutes * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceRoute **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceRoutes * This);
        
        END_INTERFACE
    } IInterfaceRoutesVtbl;

    interface IInterfaceRoutes
    {
        CONST_VTBL struct IInterfaceRoutesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceRoutes_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceRoutes_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceRoutes_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceRoutes_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceRoutes_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceRoutes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceRoutes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceRoutes_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceRoutes_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceRoutes_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceRoutes_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceRoutes_get_ItemByName(This,ItemName,pVal)	\
    ( (This)->lpVtbl -> get_ItemByName(This,ItemName,pVal) ) 

#define IInterfaceRoutes_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceRoutes_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceRoutes_INTERFACE_DEFINED__ */


#ifndef __IInterfaceRouteAddress_INTERFACE_DEFINED__
#define __IInterfaceRouteAddress_INTERFACE_DEFINED__

/* interface IInterfaceRouteAddress */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceRouteAddress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FD22CA52-BBF4-45BB-9165-986B3F4B5C77")
    IInterfaceRouteAddress : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Address( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Address( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RouteID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RouteID( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceRouteAddressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceRouteAddress * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceRouteAddress * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceRouteAddress * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceRouteAddress * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceRouteAddress * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceRouteAddress * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceRouteAddress * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceRouteAddress * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Address )( 
            IInterfaceRouteAddress * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Address )( 
            IInterfaceRouteAddress * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RouteID )( 
            IInterfaceRouteAddress * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RouteID )( 
            IInterfaceRouteAddress * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceRouteAddress * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceRouteAddress * This);
        
        END_INTERFACE
    } IInterfaceRouteAddressVtbl;

    interface IInterfaceRouteAddress
    {
        CONST_VTBL struct IInterfaceRouteAddressVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceRouteAddress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceRouteAddress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceRouteAddress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceRouteAddress_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceRouteAddress_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceRouteAddress_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceRouteAddress_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceRouteAddress_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceRouteAddress_get_Address(This,pVal)	\
    ( (This)->lpVtbl -> get_Address(This,pVal) ) 

#define IInterfaceRouteAddress_put_Address(This,newVal)	\
    ( (This)->lpVtbl -> put_Address(This,newVal) ) 

#define IInterfaceRouteAddress_get_RouteID(This,pVal)	\
    ( (This)->lpVtbl -> get_RouteID(This,pVal) ) 

#define IInterfaceRouteAddress_put_RouteID(This,newVal)	\
    ( (This)->lpVtbl -> put_RouteID(This,newVal) ) 

#define IInterfaceRouteAddress_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceRouteAddress_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceRouteAddress_INTERFACE_DEFINED__ */


#ifndef __IInterfaceRouteAddresses_INTERFACE_DEFINED__
#define __IInterfaceRouteAddresses_INTERFACE_DEFINED__

/* interface IInterfaceRouteAddresses */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceRouteAddresses;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("315BF27F-F832-4FBE-83FE-1C5A5011FAC7")
    IInterfaceRouteAddresses : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceRouteAddress **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceRouteAddress **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByAddress( 
            /* [in] */ BSTR sAddress) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceRouteAddress **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceRouteAddressesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceRouteAddresses * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceRouteAddresses * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceRouteAddresses * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceRouteAddresses * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceRouteAddresses * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceRouteAddresses * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceRouteAddresses * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceRouteAddresses * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceRouteAddress **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceRouteAddresses * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceRouteAddresses * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceRouteAddresses * This,
            /* [retval][out] */ IInterfaceRouteAddress **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByAddress )( 
            IInterfaceRouteAddresses * This,
            /* [in] */ BSTR sAddress);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceRouteAddresses * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceRouteAddress **pVal);
        
        END_INTERFACE
    } IInterfaceRouteAddressesVtbl;

    interface IInterfaceRouteAddresses
    {
        CONST_VTBL struct IInterfaceRouteAddressesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceRouteAddresses_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceRouteAddresses_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceRouteAddresses_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceRouteAddresses_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceRouteAddresses_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceRouteAddresses_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceRouteAddresses_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceRouteAddresses_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceRouteAddresses_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceRouteAddresses_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceRouteAddresses_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceRouteAddresses_DeleteByAddress(This,sAddress)	\
    ( (This)->lpVtbl -> DeleteByAddress(This,sAddress) ) 

#define IInterfaceRouteAddresses_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceRouteAddresses_INTERFACE_DEFINED__ */


#ifndef __IInterfaceResult_INTERFACE_DEFINED__
#define __IInterfaceResult_INTERFACE_DEFINED__

/* interface IInterfaceResult */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceResult;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9038AE3E-CD88-4306-9A08-07F2580D50A0")
    IInterfaceResult : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Message( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Message( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parameter( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Parameter( 
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceResultVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceResult * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceResult * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceResult * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceResult * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceResult * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceResult * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceResult * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IInterfaceResult * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IInterfaceResult * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Message )( 
            IInterfaceResult * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Message )( 
            IInterfaceResult * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parameter )( 
            IInterfaceResult * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Parameter )( 
            IInterfaceResult * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IInterfaceResultVtbl;

    interface IInterfaceResult
    {
        CONST_VTBL struct IInterfaceResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceResult_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceResult_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceResult_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceResult_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceResult_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceResult_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceResult_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceResult_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#define IInterfaceResult_put_Value(This,newVal)	\
    ( (This)->lpVtbl -> put_Value(This,newVal) ) 

#define IInterfaceResult_get_Message(This,pVal)	\
    ( (This)->lpVtbl -> get_Message(This,pVal) ) 

#define IInterfaceResult_put_Message(This,newVal)	\
    ( (This)->lpVtbl -> put_Message(This,newVal) ) 

#define IInterfaceResult_get_Parameter(This,pVal)	\
    ( (This)->lpVtbl -> get_Parameter(This,pVal) ) 

#define IInterfaceResult_put_Parameter(This,newVal)	\
    ( (This)->lpVtbl -> put_Parameter(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceResult_INTERFACE_DEFINED__ */


#ifndef __IInterfaceClient_INTERFACE_DEFINED__
#define __IInterfaceClient_INTERFACE_DEFINED__

/* interface IInterfaceClient */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("63D8A81C-E3BA-4768-9F14-0FCF5A6844D7")
    IInterfaceClient : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Port( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IPAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Username( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HELO( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceClient * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceClient * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceClient * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceClient * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceClient * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Port )( 
            IInterfaceClient * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IPAddress )( 
            IInterfaceClient * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Username )( 
            IInterfaceClient * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HELO )( 
            IInterfaceClient * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IInterfaceClientVtbl;

    interface IInterfaceClient
    {
        CONST_VTBL struct IInterfaceClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceClient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceClient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceClient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceClient_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceClient_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceClient_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceClient_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceClient_get_Port(This,pVal)	\
    ( (This)->lpVtbl -> get_Port(This,pVal) ) 

#define IInterfaceClient_get_IPAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_IPAddress(This,pVal) ) 

#define IInterfaceClient_get_Username(This,pVal)	\
    ( (This)->lpVtbl -> get_Username(This,pVal) ) 

#define IInterfaceClient_get_HELO(This,pVal)	\
    ( (This)->lpVtbl -> get_HELO(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceClient_INTERFACE_DEFINED__ */


#ifndef __IInterfaceFetchAccount_INTERFACE_DEFINED__
#define __IInterfaceFetchAccount_INTERFACE_DEFINED__

/* interface IInterfaceFetchAccount */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceFetchAccount;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("752C1F5E-74DD-424F-AB60-07D9ABB5B7A4")
    IInterfaceFetchAccount : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServerAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ServerAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Port( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Port( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ServerType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ServerType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Username( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Username( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Password( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Password( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinutesBetweenFetch( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MinutesBetweenFetch( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DaysToKeepMessages( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DaysToKeepMessages( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AccountID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AccountID( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProcessMIMERecipients( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProcessMIMERecipients( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DownloadNow( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProcessMIMEDate( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProcessMIMEDate( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseSSL( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseSSL( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NextDownloadTime( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseAntiSpam( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseAntiSpam( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseAntiVirus( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseAntiVirus( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableRouteRecipients( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableRouteRecipients( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceFetchAccountVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceFetchAccount * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceFetchAccount * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceFetchAccount * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceFetchAccount * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceFetchAccount * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceFetchAccount * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceFetchAccount * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IInterfaceFetchAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServerAddress )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ServerAddress )( 
            IInterfaceFetchAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Port )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Port )( 
            IInterfaceFetchAccount * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ServerType )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ServerType )( 
            IInterfaceFetchAccount * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Username )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Username )( 
            IInterfaceFetchAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Password )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Password )( 
            IInterfaceFetchAccount * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MinutesBetweenFetch )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MinutesBetweenFetch )( 
            IInterfaceFetchAccount * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DaysToKeepMessages )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DaysToKeepMessages )( 
            IInterfaceFetchAccount * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceFetchAccount * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AccountID )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AccountID )( 
            IInterfaceFetchAccount * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IInterfaceFetchAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProcessMIMERecipients )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ProcessMIMERecipients )( 
            IInterfaceFetchAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DownloadNow )( 
            IInterfaceFetchAccount * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProcessMIMEDate )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ProcessMIMEDate )( 
            IInterfaceFetchAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseSSL )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseSSL )( 
            IInterfaceFetchAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceFetchAccount * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NextDownloadTime )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseAntiSpam )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseAntiSpam )( 
            IInterfaceFetchAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseAntiVirus )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseAntiVirus )( 
            IInterfaceFetchAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableRouteRecipients )( 
            IInterfaceFetchAccount * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableRouteRecipients )( 
            IInterfaceFetchAccount * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } IInterfaceFetchAccountVtbl;

    interface IInterfaceFetchAccount
    {
        CONST_VTBL struct IInterfaceFetchAccountVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceFetchAccount_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceFetchAccount_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceFetchAccount_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceFetchAccount_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceFetchAccount_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceFetchAccount_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceFetchAccount_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceFetchAccount_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceFetchAccount_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceFetchAccount_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IInterfaceFetchAccount_get_ServerAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_ServerAddress(This,pVal) ) 

#define IInterfaceFetchAccount_put_ServerAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_ServerAddress(This,newVal) ) 

#define IInterfaceFetchAccount_get_Port(This,pVal)	\
    ( (This)->lpVtbl -> get_Port(This,pVal) ) 

#define IInterfaceFetchAccount_put_Port(This,newVal)	\
    ( (This)->lpVtbl -> put_Port(This,newVal) ) 

#define IInterfaceFetchAccount_get_ServerType(This,pVal)	\
    ( (This)->lpVtbl -> get_ServerType(This,pVal) ) 

#define IInterfaceFetchAccount_put_ServerType(This,newVal)	\
    ( (This)->lpVtbl -> put_ServerType(This,newVal) ) 

#define IInterfaceFetchAccount_get_Username(This,pVal)	\
    ( (This)->lpVtbl -> get_Username(This,pVal) ) 

#define IInterfaceFetchAccount_put_Username(This,newVal)	\
    ( (This)->lpVtbl -> put_Username(This,newVal) ) 

#define IInterfaceFetchAccount_get_Password(This,pVal)	\
    ( (This)->lpVtbl -> get_Password(This,pVal) ) 

#define IInterfaceFetchAccount_put_Password(This,newVal)	\
    ( (This)->lpVtbl -> put_Password(This,newVal) ) 

#define IInterfaceFetchAccount_get_MinutesBetweenFetch(This,pVal)	\
    ( (This)->lpVtbl -> get_MinutesBetweenFetch(This,pVal) ) 

#define IInterfaceFetchAccount_put_MinutesBetweenFetch(This,newVal)	\
    ( (This)->lpVtbl -> put_MinutesBetweenFetch(This,newVal) ) 

#define IInterfaceFetchAccount_get_DaysToKeepMessages(This,pVal)	\
    ( (This)->lpVtbl -> get_DaysToKeepMessages(This,pVal) ) 

#define IInterfaceFetchAccount_put_DaysToKeepMessages(This,newVal)	\
    ( (This)->lpVtbl -> put_DaysToKeepMessages(This,newVal) ) 

#define IInterfaceFetchAccount_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceFetchAccount_get_AccountID(This,pVal)	\
    ( (This)->lpVtbl -> get_AccountID(This,pVal) ) 

#define IInterfaceFetchAccount_put_AccountID(This,newVal)	\
    ( (This)->lpVtbl -> put_AccountID(This,newVal) ) 

#define IInterfaceFetchAccount_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define IInterfaceFetchAccount_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define IInterfaceFetchAccount_get_ProcessMIMERecipients(This,pVal)	\
    ( (This)->lpVtbl -> get_ProcessMIMERecipients(This,pVal) ) 

#define IInterfaceFetchAccount_put_ProcessMIMERecipients(This,newVal)	\
    ( (This)->lpVtbl -> put_ProcessMIMERecipients(This,newVal) ) 

#define IInterfaceFetchAccount_DownloadNow(This)	\
    ( (This)->lpVtbl -> DownloadNow(This) ) 

#define IInterfaceFetchAccount_get_ProcessMIMEDate(This,pVal)	\
    ( (This)->lpVtbl -> get_ProcessMIMEDate(This,pVal) ) 

#define IInterfaceFetchAccount_put_ProcessMIMEDate(This,newVal)	\
    ( (This)->lpVtbl -> put_ProcessMIMEDate(This,newVal) ) 

#define IInterfaceFetchAccount_get_UseSSL(This,pVal)	\
    ( (This)->lpVtbl -> get_UseSSL(This,pVal) ) 

#define IInterfaceFetchAccount_put_UseSSL(This,newVal)	\
    ( (This)->lpVtbl -> put_UseSSL(This,newVal) ) 

#define IInterfaceFetchAccount_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IInterfaceFetchAccount_get_NextDownloadTime(This,pVal)	\
    ( (This)->lpVtbl -> get_NextDownloadTime(This,pVal) ) 

#define IInterfaceFetchAccount_get_UseAntiSpam(This,pVal)	\
    ( (This)->lpVtbl -> get_UseAntiSpam(This,pVal) ) 

#define IInterfaceFetchAccount_put_UseAntiSpam(This,newVal)	\
    ( (This)->lpVtbl -> put_UseAntiSpam(This,newVal) ) 

#define IInterfaceFetchAccount_get_UseAntiVirus(This,pVal)	\
    ( (This)->lpVtbl -> get_UseAntiVirus(This,pVal) ) 

#define IInterfaceFetchAccount_put_UseAntiVirus(This,newVal)	\
    ( (This)->lpVtbl -> put_UseAntiVirus(This,newVal) ) 

#define IInterfaceFetchAccount_get_EnableRouteRecipients(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableRouteRecipients(This,pVal) ) 

#define IInterfaceFetchAccount_put_EnableRouteRecipients(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableRouteRecipients(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceFetchAccount_INTERFACE_DEFINED__ */


#ifndef __IInterfaceFetchAccounts_INTERFACE_DEFINED__
#define __IInterfaceFetchAccounts_INTERFACE_DEFINED__

/* interface IInterfaceFetchAccounts */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceFetchAccounts;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1517E0BE-5226-46CC-8C2A-BB16B680FF48")
    IInterfaceFetchAccounts : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceFetchAccount **pVal) = 0;
        
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceFetchAccount **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            long Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceFetchAccount **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceFetchAccountsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceFetchAccounts * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceFetchAccounts * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceFetchAccounts * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceFetchAccounts * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceFetchAccounts * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceFetchAccounts * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceFetchAccounts * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceFetchAccounts * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceFetchAccounts * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceFetchAccount **pVal);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceFetchAccounts * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceFetchAccount **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceFetchAccounts * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceFetchAccounts * This,
            long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceFetchAccounts * This,
            long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceFetchAccounts * This,
            /* [retval][out] */ IInterfaceFetchAccount **pVal);
        
        END_INTERFACE
    } IInterfaceFetchAccountsVtbl;

    interface IInterfaceFetchAccounts
    {
        CONST_VTBL struct IInterfaceFetchAccountsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceFetchAccounts_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceFetchAccounts_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceFetchAccounts_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceFetchAccounts_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceFetchAccounts_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceFetchAccounts_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceFetchAccounts_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceFetchAccounts_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceFetchAccounts_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceFetchAccounts_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceFetchAccounts_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceFetchAccounts_Delete(This,Index)	\
    ( (This)->lpVtbl -> Delete(This,Index) ) 

#define IInterfaceFetchAccounts_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceFetchAccounts_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceFetchAccounts_INTERFACE_DEFINED__ */


#ifndef __IInterfaceScripting_INTERFACE_DEFINED__
#define __IInterfaceScripting_INTERFACE_DEFINED__

/* interface IInterfaceScripting */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceScripting;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B1EA04C0-B0B7-4638-80E4-41278CEF8C19")
    IInterfaceScripting : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Language( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Language( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Reload( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckSyntax( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Directory( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentScriptFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceScriptingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceScripting * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceScripting * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceScripting * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceScripting * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceScripting * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceScripting * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceScripting * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IInterfaceScripting * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IInterfaceScripting * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Language )( 
            IInterfaceScripting * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Language )( 
            IInterfaceScripting * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Reload )( 
            IInterfaceScripting * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckSyntax )( 
            IInterfaceScripting * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Directory )( 
            IInterfaceScripting * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentScriptFile )( 
            IInterfaceScripting * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IInterfaceScriptingVtbl;

    interface IInterfaceScripting
    {
        CONST_VTBL struct IInterfaceScriptingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceScripting_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceScripting_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceScripting_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceScripting_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceScripting_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceScripting_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceScripting_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceScripting_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define IInterfaceScripting_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define IInterfaceScripting_get_Language(This,pVal)	\
    ( (This)->lpVtbl -> get_Language(This,pVal) ) 

#define IInterfaceScripting_put_Language(This,newVal)	\
    ( (This)->lpVtbl -> put_Language(This,newVal) ) 

#define IInterfaceScripting_Reload(This)	\
    ( (This)->lpVtbl -> Reload(This) ) 

#define IInterfaceScripting_CheckSyntax(This,pVal)	\
    ( (This)->lpVtbl -> CheckSyntax(This,pVal) ) 

#define IInterfaceScripting_get_Directory(This,pVal)	\
    ( (This)->lpVtbl -> get_Directory(This,pVal) ) 

#define IInterfaceScripting_get_CurrentScriptFile(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentScriptFile(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceScripting_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDomainAliases_INTERFACE_DEFINED__
#define __IInterfaceDomainAliases_INTERFACE_DEFINED__

/* interface IInterfaceDomainAliases */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDomainAliases;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E4100C8D-E956-449C-A96D-261DDC33AE4F")
    IInterfaceDomainAliases : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceDomainAlias **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDomainAlias **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            long Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceDomainAlias **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDomainAliasesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDomainAliases * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDomainAliases * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDomainAliases * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDomainAliases * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDomainAliases * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDomainAliases * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDomainAliases * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceDomainAliases * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceDomainAlias **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceDomainAliases * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceDomainAliases * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDomainAlias **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceDomainAliases * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceDomainAliases * This,
            long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceDomainAliases * This,
            long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceDomainAliases * This,
            /* [retval][out] */ IInterfaceDomainAlias **pVal);
        
        END_INTERFACE
    } IInterfaceDomainAliasesVtbl;

    interface IInterfaceDomainAliases
    {
        CONST_VTBL struct IInterfaceDomainAliasesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDomainAliases_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDomainAliases_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDomainAliases_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDomainAliases_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDomainAliases_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDomainAliases_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDomainAliases_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDomainAliases_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceDomainAliases_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceDomainAliases_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceDomainAliases_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceDomainAliases_Delete(This,Index)	\
    ( (This)->lpVtbl -> Delete(This,Index) ) 

#define IInterfaceDomainAliases_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceDomainAliases_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDomainAliases_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDomainAlias_INTERFACE_DEFINED__
#define __IInterfaceDomainAlias_INTERFACE_DEFINED__

/* interface IInterfaceDomainAlias */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDomainAlias;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8FD251D8-AAF1-4143-B185-E6C1BF281826")
    IInterfaceDomainAlias : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AliasName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AliasName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DomainID( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDomainAliasVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDomainAlias * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDomainAlias * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDomainAlias * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDomainAlias * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDomainAlias * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDomainAlias * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDomainAlias * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceDomainAlias * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AliasName )( 
            IInterfaceDomainAlias * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AliasName )( 
            IInterfaceDomainAlias * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DomainID )( 
            IInterfaceDomainAlias * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DomainID )( 
            IInterfaceDomainAlias * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceDomainAlias * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceDomainAlias * This);
        
        END_INTERFACE
    } IInterfaceDomainAliasVtbl;

    interface IInterfaceDomainAlias
    {
        CONST_VTBL struct IInterfaceDomainAliasVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDomainAlias_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDomainAlias_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDomainAlias_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDomainAlias_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDomainAlias_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDomainAlias_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDomainAlias_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDomainAlias_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceDomainAlias_get_AliasName(This,pVal)	\
    ( (This)->lpVtbl -> get_AliasName(This,pVal) ) 

#define IInterfaceDomainAlias_put_AliasName(This,newVal)	\
    ( (This)->lpVtbl -> put_AliasName(This,newVal) ) 

#define IInterfaceDomainAlias_get_DomainID(This,pVal)	\
    ( (This)->lpVtbl -> get_DomainID(This,pVal) ) 

#define IInterfaceDomainAlias_put_DomainID(This,newVal)	\
    ( (This)->lpVtbl -> put_DomainID(This,newVal) ) 

#define IInterfaceDomainAlias_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceDomainAlias_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDomainAlias_INTERFACE_DEFINED__ */


#ifndef __IInterfaceRules_INTERFACE_DEFINED__
#define __IInterfaceRules_INTERFACE_DEFINED__

/* interface IInterfaceRules */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceRules;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("995F9181-E761-42FA-9057-FE070B37D0F3")
    IInterfaceRules : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceRule **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceRule **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceRule **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ LONG DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceRulesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceRules * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceRules * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceRules * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceRules * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceRules * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceRules * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceRules * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceRules * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceRule **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceRules * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceRule **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceRules * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceRules * This,
            /* [retval][out] */ IInterfaceRule **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceRules * This,
            /* [in] */ LONG DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceRules * This);
        
        END_INTERFACE
    } IInterfaceRulesVtbl;

    interface IInterfaceRules
    {
        CONST_VTBL struct IInterfaceRulesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceRules_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceRules_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceRules_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceRules_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceRules_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceRules_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceRules_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceRules_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceRules_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceRules_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceRules_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceRules_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceRules_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceRules_INTERFACE_DEFINED__ */


#ifndef __IInterfaceRule_INTERFACE_DEFINED__
#define __IInterfaceRule_INTERFACE_DEFINED__

/* interface IInterfaceRule */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceRule;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("41CCD467-9ADE-4ADA-AE14-760E94BA53E8")
    IInterfaceRule : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AccountID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AccountID( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Active( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseAND( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseAND( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Criterias( 
            /* [retval][out] */ IInterfaceRuleCriterias **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Actions( 
            /* [retval][out] */ IInterfaceRuleActions **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveUp( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveDown( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceRuleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceRule * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceRule * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceRule * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceRule * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceRule * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceRule * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceRule * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceRule * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AccountID )( 
            IInterfaceRule * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AccountID )( 
            IInterfaceRule * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceRule * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IInterfaceRule * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Active )( 
            IInterfaceRule * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Active )( 
            IInterfaceRule * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseAND )( 
            IInterfaceRule * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseAND )( 
            IInterfaceRule * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Criterias )( 
            IInterfaceRule * This,
            /* [retval][out] */ IInterfaceRuleCriterias **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Actions )( 
            IInterfaceRule * This,
            /* [retval][out] */ IInterfaceRuleActions **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceRule * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveUp )( 
            IInterfaceRule * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveDown )( 
            IInterfaceRule * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceRule * This);
        
        END_INTERFACE
    } IInterfaceRuleVtbl;

    interface IInterfaceRule
    {
        CONST_VTBL struct IInterfaceRuleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceRule_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceRule_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceRule_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceRule_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceRule_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceRule_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceRule_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceRule_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceRule_get_AccountID(This,pVal)	\
    ( (This)->lpVtbl -> get_AccountID(This,pVal) ) 

#define IInterfaceRule_put_AccountID(This,newVal)	\
    ( (This)->lpVtbl -> put_AccountID(This,newVal) ) 

#define IInterfaceRule_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceRule_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IInterfaceRule_get_Active(This,pVal)	\
    ( (This)->lpVtbl -> get_Active(This,pVal) ) 

#define IInterfaceRule_put_Active(This,newVal)	\
    ( (This)->lpVtbl -> put_Active(This,newVal) ) 

#define IInterfaceRule_get_UseAND(This,pVal)	\
    ( (This)->lpVtbl -> get_UseAND(This,pVal) ) 

#define IInterfaceRule_put_UseAND(This,newVal)	\
    ( (This)->lpVtbl -> put_UseAND(This,newVal) ) 

#define IInterfaceRule_get_Criterias(This,pVal)	\
    ( (This)->lpVtbl -> get_Criterias(This,pVal) ) 

#define IInterfaceRule_get_Actions(This,pVal)	\
    ( (This)->lpVtbl -> get_Actions(This,pVal) ) 

#define IInterfaceRule_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceRule_MoveUp(This)	\
    ( (This)->lpVtbl -> MoveUp(This) ) 

#define IInterfaceRule_MoveDown(This)	\
    ( (This)->lpVtbl -> MoveDown(This) ) 

#define IInterfaceRule_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceRule_INTERFACE_DEFINED__ */


#ifndef __IInterfaceRuleCriteria_INTERFACE_DEFINED__
#define __IInterfaceRuleCriteria_INTERFACE_DEFINED__

/* interface IInterfaceRuleCriteria */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceRuleCriteria;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2D8AA7DE-6155-44A5-802D-9FEC611A50A9")
    IInterfaceRuleCriteria : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RuleID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RuleID( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MatchValue( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MatchValue( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UsePredefined( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UsePredefined( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PredefinedField( 
            /* [retval][out] */ eRulePredefinedField *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PredefinedField( 
            /* [in] */ eRulePredefinedField newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MatchType( 
            /* [retval][out] */ eRuleMatchType *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MatchType( 
            /* [in] */ eRuleMatchType newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HeaderField( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HeaderField( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceRuleCriteriaVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceRuleCriteria * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceRuleCriteria * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceRuleCriteria * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceRuleCriteria * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceRuleCriteria * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceRuleCriteria * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceRuleCriteria * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceRuleCriteria * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RuleID )( 
            IInterfaceRuleCriteria * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RuleID )( 
            IInterfaceRuleCriteria * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MatchValue )( 
            IInterfaceRuleCriteria * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MatchValue )( 
            IInterfaceRuleCriteria * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UsePredefined )( 
            IInterfaceRuleCriteria * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UsePredefined )( 
            IInterfaceRuleCriteria * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PredefinedField )( 
            IInterfaceRuleCriteria * This,
            /* [retval][out] */ eRulePredefinedField *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PredefinedField )( 
            IInterfaceRuleCriteria * This,
            /* [in] */ eRulePredefinedField newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MatchType )( 
            IInterfaceRuleCriteria * This,
            /* [retval][out] */ eRuleMatchType *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MatchType )( 
            IInterfaceRuleCriteria * This,
            /* [in] */ eRuleMatchType newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HeaderField )( 
            IInterfaceRuleCriteria * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HeaderField )( 
            IInterfaceRuleCriteria * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceRuleCriteria * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceRuleCriteria * This);
        
        END_INTERFACE
    } IInterfaceRuleCriteriaVtbl;

    interface IInterfaceRuleCriteria
    {
        CONST_VTBL struct IInterfaceRuleCriteriaVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceRuleCriteria_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceRuleCriteria_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceRuleCriteria_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceRuleCriteria_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceRuleCriteria_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceRuleCriteria_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceRuleCriteria_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceRuleCriteria_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceRuleCriteria_get_RuleID(This,pVal)	\
    ( (This)->lpVtbl -> get_RuleID(This,pVal) ) 

#define IInterfaceRuleCriteria_put_RuleID(This,newVal)	\
    ( (This)->lpVtbl -> put_RuleID(This,newVal) ) 

#define IInterfaceRuleCriteria_get_MatchValue(This,pVal)	\
    ( (This)->lpVtbl -> get_MatchValue(This,pVal) ) 

#define IInterfaceRuleCriteria_put_MatchValue(This,newVal)	\
    ( (This)->lpVtbl -> put_MatchValue(This,newVal) ) 

#define IInterfaceRuleCriteria_get_UsePredefined(This,pVal)	\
    ( (This)->lpVtbl -> get_UsePredefined(This,pVal) ) 

#define IInterfaceRuleCriteria_put_UsePredefined(This,newVal)	\
    ( (This)->lpVtbl -> put_UsePredefined(This,newVal) ) 

#define IInterfaceRuleCriteria_get_PredefinedField(This,pVal)	\
    ( (This)->lpVtbl -> get_PredefinedField(This,pVal) ) 

#define IInterfaceRuleCriteria_put_PredefinedField(This,newVal)	\
    ( (This)->lpVtbl -> put_PredefinedField(This,newVal) ) 

#define IInterfaceRuleCriteria_get_MatchType(This,pVal)	\
    ( (This)->lpVtbl -> get_MatchType(This,pVal) ) 

#define IInterfaceRuleCriteria_put_MatchType(This,newVal)	\
    ( (This)->lpVtbl -> put_MatchType(This,newVal) ) 

#define IInterfaceRuleCriteria_get_HeaderField(This,pVal)	\
    ( (This)->lpVtbl -> get_HeaderField(This,pVal) ) 

#define IInterfaceRuleCriteria_put_HeaderField(This,newVal)	\
    ( (This)->lpVtbl -> put_HeaderField(This,newVal) ) 

#define IInterfaceRuleCriteria_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceRuleCriteria_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceRuleCriteria_INTERFACE_DEFINED__ */


#ifndef __IInterfaceRuleCriterias_INTERFACE_DEFINED__
#define __IInterfaceRuleCriterias_INTERFACE_DEFINED__

/* interface IInterfaceRuleCriterias */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceRuleCriterias;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D79148F6-78A9-4F60-B8E8-48C33D888FC5")
    IInterfaceRuleCriterias : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceRuleCriteria **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceRuleCriteria **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceRuleCriteria **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ LONG DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ long DBID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceRuleCriteriasVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceRuleCriterias * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceRuleCriterias * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceRuleCriterias * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceRuleCriterias * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceRuleCriterias * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceRuleCriterias * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceRuleCriterias * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceRuleCriterias * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceRuleCriteria **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceRuleCriterias * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceRuleCriteria **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceRuleCriterias * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceRuleCriterias * This,
            /* [retval][out] */ IInterfaceRuleCriteria **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceRuleCriterias * This,
            /* [in] */ LONG DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceRuleCriterias * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceRuleCriterias * This,
            /* [in] */ long DBID);
        
        END_INTERFACE
    } IInterfaceRuleCriteriasVtbl;

    interface IInterfaceRuleCriterias
    {
        CONST_VTBL struct IInterfaceRuleCriteriasVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceRuleCriterias_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceRuleCriterias_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceRuleCriterias_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceRuleCriterias_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceRuleCriterias_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceRuleCriterias_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceRuleCriterias_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceRuleCriterias_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceRuleCriterias_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceRuleCriterias_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceRuleCriterias_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceRuleCriterias_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceRuleCriterias_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceRuleCriterias_Delete(This,DBID)	\
    ( (This)->lpVtbl -> Delete(This,DBID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceRuleCriterias_INTERFACE_DEFINED__ */


#ifndef __IInterfaceRuleAction_INTERFACE_DEFINED__
#define __IInterfaceRuleAction_INTERFACE_DEFINED__

/* interface IInterfaceRuleAction */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceRuleAction;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F3F4A3E1-695E-499E-9F31-712DA8126982")
    IInterfaceRuleAction : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RuleID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RuleID( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ eRuleActionType *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Type( 
            /* [in] */ eRuleActionType newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Subject( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Subject( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Body( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Body( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FromName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FromName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_FromAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_FromAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Filename( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Filename( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_To( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_To( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IMAPFolder( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IMAPFolder( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ScriptFunction( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ScriptFunction( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveUp( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveDown( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HeaderName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HeaderName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RouteID( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RouteID( 
            /* [in] */ LONG newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceRuleActionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceRuleAction * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceRuleAction * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceRuleAction * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceRuleAction * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceRuleAction * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceRuleAction * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceRuleAction * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RuleID )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RuleID )( 
            IInterfaceRuleAction * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ eRuleActionType *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Type )( 
            IInterfaceRuleAction * This,
            /* [in] */ eRuleActionType newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Subject )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Subject )( 
            IInterfaceRuleAction * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Body )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Body )( 
            IInterfaceRuleAction * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FromName )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FromName )( 
            IInterfaceRuleAction * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FromAddress )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FromAddress )( 
            IInterfaceRuleAction * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Filename )( 
            IInterfaceRuleAction * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_To )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_To )( 
            IInterfaceRuleAction * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IMAPFolder )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IMAPFolder )( 
            IInterfaceRuleAction * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceRuleAction * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ScriptFunction )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ScriptFunction )( 
            IInterfaceRuleAction * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveUp )( 
            IInterfaceRuleAction * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveDown )( 
            IInterfaceRuleAction * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HeaderName )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HeaderName )( 
            IInterfaceRuleAction * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IInterfaceRuleAction * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceRuleAction * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RouteID )( 
            IInterfaceRuleAction * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RouteID )( 
            IInterfaceRuleAction * This,
            /* [in] */ LONG newVal);
        
        END_INTERFACE
    } IInterfaceRuleActionVtbl;

    interface IInterfaceRuleAction
    {
        CONST_VTBL struct IInterfaceRuleActionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceRuleAction_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceRuleAction_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceRuleAction_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceRuleAction_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceRuleAction_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceRuleAction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceRuleAction_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceRuleAction_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceRuleAction_get_RuleID(This,pVal)	\
    ( (This)->lpVtbl -> get_RuleID(This,pVal) ) 

#define IInterfaceRuleAction_put_RuleID(This,newVal)	\
    ( (This)->lpVtbl -> put_RuleID(This,newVal) ) 

#define IInterfaceRuleAction_get_Type(This,pVal)	\
    ( (This)->lpVtbl -> get_Type(This,pVal) ) 

#define IInterfaceRuleAction_put_Type(This,newVal)	\
    ( (This)->lpVtbl -> put_Type(This,newVal) ) 

#define IInterfaceRuleAction_get_Subject(This,pVal)	\
    ( (This)->lpVtbl -> get_Subject(This,pVal) ) 

#define IInterfaceRuleAction_put_Subject(This,newVal)	\
    ( (This)->lpVtbl -> put_Subject(This,newVal) ) 

#define IInterfaceRuleAction_get_Body(This,pVal)	\
    ( (This)->lpVtbl -> get_Body(This,pVal) ) 

#define IInterfaceRuleAction_put_Body(This,newVal)	\
    ( (This)->lpVtbl -> put_Body(This,newVal) ) 

#define IInterfaceRuleAction_get_FromName(This,pVal)	\
    ( (This)->lpVtbl -> get_FromName(This,pVal) ) 

#define IInterfaceRuleAction_put_FromName(This,newVal)	\
    ( (This)->lpVtbl -> put_FromName(This,newVal) ) 

#define IInterfaceRuleAction_get_FromAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_FromAddress(This,pVal) ) 

#define IInterfaceRuleAction_put_FromAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_FromAddress(This,newVal) ) 

#define IInterfaceRuleAction_get_Filename(This,pVal)	\
    ( (This)->lpVtbl -> get_Filename(This,pVal) ) 

#define IInterfaceRuleAction_put_Filename(This,newVal)	\
    ( (This)->lpVtbl -> put_Filename(This,newVal) ) 

#define IInterfaceRuleAction_get_To(This,pVal)	\
    ( (This)->lpVtbl -> get_To(This,pVal) ) 

#define IInterfaceRuleAction_put_To(This,newVal)	\
    ( (This)->lpVtbl -> put_To(This,newVal) ) 

#define IInterfaceRuleAction_get_IMAPFolder(This,pVal)	\
    ( (This)->lpVtbl -> get_IMAPFolder(This,pVal) ) 

#define IInterfaceRuleAction_put_IMAPFolder(This,newVal)	\
    ( (This)->lpVtbl -> put_IMAPFolder(This,newVal) ) 

#define IInterfaceRuleAction_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceRuleAction_get_ScriptFunction(This,pVal)	\
    ( (This)->lpVtbl -> get_ScriptFunction(This,pVal) ) 

#define IInterfaceRuleAction_put_ScriptFunction(This,newVal)	\
    ( (This)->lpVtbl -> put_ScriptFunction(This,newVal) ) 

#define IInterfaceRuleAction_MoveUp(This)	\
    ( (This)->lpVtbl -> MoveUp(This) ) 

#define IInterfaceRuleAction_MoveDown(This)	\
    ( (This)->lpVtbl -> MoveDown(This) ) 

#define IInterfaceRuleAction_get_HeaderName(This,pVal)	\
    ( (This)->lpVtbl -> get_HeaderName(This,pVal) ) 

#define IInterfaceRuleAction_put_HeaderName(This,newVal)	\
    ( (This)->lpVtbl -> put_HeaderName(This,newVal) ) 

#define IInterfaceRuleAction_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#define IInterfaceRuleAction_put_Value(This,newVal)	\
    ( (This)->lpVtbl -> put_Value(This,newVal) ) 

#define IInterfaceRuleAction_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IInterfaceRuleAction_get_RouteID(This,pVal)	\
    ( (This)->lpVtbl -> get_RouteID(This,pVal) ) 

#define IInterfaceRuleAction_put_RouteID(This,newVal)	\
    ( (This)->lpVtbl -> put_RouteID(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceRuleAction_INTERFACE_DEFINED__ */


#ifndef __IInterfaceRuleActions_INTERFACE_DEFINED__
#define __IInterfaceRuleActions_INTERFACE_DEFINED__

/* interface IInterfaceRuleActions */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceRuleActions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DBFD3E11-9121-4DDD-944B-5AF29BF3D2DF")
    IInterfaceRuleActions : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceRuleAction **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceRuleAction **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceRuleAction **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ LONG DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ long DBID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceRuleActionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceRuleActions * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceRuleActions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceRuleActions * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceRuleActions * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceRuleActions * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceRuleActions * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceRuleActions * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceRuleActions * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceRuleAction **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceRuleActions * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceRuleAction **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceRuleActions * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceRuleActions * This,
            /* [retval][out] */ IInterfaceRuleAction **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceRuleActions * This,
            /* [in] */ LONG DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceRuleActions * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceRuleActions * This,
            /* [in] */ long DBID);
        
        END_INTERFACE
    } IInterfaceRuleActionsVtbl;

    interface IInterfaceRuleActions
    {
        CONST_VTBL struct IInterfaceRuleActionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceRuleActions_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceRuleActions_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceRuleActions_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceRuleActions_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceRuleActions_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceRuleActions_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceRuleActions_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceRuleActions_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceRuleActions_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceRuleActions_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceRuleActions_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceRuleActions_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceRuleActions_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceRuleActions_Delete(This,DBID)	\
    ( (This)->lpVtbl -> Delete(This,DBID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceRuleActions_INTERFACE_DEFINED__ */


#ifndef __IInterfaceRecipients_INTERFACE_DEFINED__
#define __IInterfaceRecipients_INTERFACE_DEFINED__

/* interface IInterfaceRecipients */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceRecipients;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9B47C955-4462-48E3-91FE-C5E1CFEC80E0")
    IInterfaceRecipients : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceRecipient **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ LONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceRecipientsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceRecipients * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceRecipients * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceRecipients * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceRecipients * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceRecipients * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceRecipients * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceRecipients * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceRecipients * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceRecipient **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceRecipients * This,
            /* [retval][out] */ LONG *pVal);
        
        END_INTERFACE
    } IInterfaceRecipientsVtbl;

    interface IInterfaceRecipients
    {
        CONST_VTBL struct IInterfaceRecipientsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceRecipients_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceRecipients_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceRecipients_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceRecipients_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceRecipients_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceRecipients_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceRecipients_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceRecipients_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceRecipients_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceRecipients_INTERFACE_DEFINED__ */


#ifndef __IInterfaceRecipient_INTERFACE_DEFINED__
#define __IInterfaceRecipient_INTERFACE_DEFINED__

/* interface IInterfaceRecipient */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceRecipient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("65D57DF8-68A1-4358-BB98-C3B33595B699")
    IInterfaceRecipient : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Address( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsLocalUser( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_OriginalAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceRecipientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceRecipient * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceRecipient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceRecipient * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceRecipient * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceRecipient * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceRecipient * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceRecipient * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Address )( 
            IInterfaceRecipient * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsLocalUser )( 
            IInterfaceRecipient * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OriginalAddress )( 
            IInterfaceRecipient * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IInterfaceRecipientVtbl;

    interface IInterfaceRecipient
    {
        CONST_VTBL struct IInterfaceRecipientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceRecipient_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceRecipient_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceRecipient_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceRecipient_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceRecipient_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceRecipient_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceRecipient_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceRecipient_get_Address(This,pVal)	\
    ( (This)->lpVtbl -> get_Address(This,pVal) ) 

#define IInterfaceRecipient_get_IsLocalUser(This,pVal)	\
    ( (This)->lpVtbl -> get_IsLocalUser(This,pVal) ) 

#define IInterfaceRecipient_get_OriginalAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_OriginalAddress(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceRecipient_INTERFACE_DEFINED__ */


#ifndef __IInterfaceCache_INTERFACE_DEFINED__
#define __IInterfaceCache_INTERFACE_DEFINED__

/* interface IInterfaceCache */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceCache;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AE45B7CD-C050-4B14-A983-30D53059D24F")
    IInterfaceCache : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainCacheTTL( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DomainCacheTTL( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DomainHitRate( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AccountCacheTTL( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AccountCacheTTL( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AccountHitRate( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AliasCacheTTL( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AliasCacheTTL( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AliasHitRate( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DistributionListCacheTTL( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DistributionListCacheTTL( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DistributionListHitRate( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceCacheVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceCache * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceCache * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceCache * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceCache * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceCache * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceCache * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceCache * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IInterfaceCache * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IInterfaceCache * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DomainCacheTTL )( 
            IInterfaceCache * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DomainCacheTTL )( 
            IInterfaceCache * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DomainHitRate )( 
            IInterfaceCache * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AccountCacheTTL )( 
            IInterfaceCache * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AccountCacheTTL )( 
            IInterfaceCache * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AccountHitRate )( 
            IInterfaceCache * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IInterfaceCache * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AliasCacheTTL )( 
            IInterfaceCache * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AliasCacheTTL )( 
            IInterfaceCache * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AliasHitRate )( 
            IInterfaceCache * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DistributionListCacheTTL )( 
            IInterfaceCache * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DistributionListCacheTTL )( 
            IInterfaceCache * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DistributionListHitRate )( 
            IInterfaceCache * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } IInterfaceCacheVtbl;

    interface IInterfaceCache
    {
        CONST_VTBL struct IInterfaceCacheVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceCache_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceCache_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceCache_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceCache_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceCache_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceCache_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceCache_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceCache_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define IInterfaceCache_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define IInterfaceCache_get_DomainCacheTTL(This,pVal)	\
    ( (This)->lpVtbl -> get_DomainCacheTTL(This,pVal) ) 

#define IInterfaceCache_put_DomainCacheTTL(This,newVal)	\
    ( (This)->lpVtbl -> put_DomainCacheTTL(This,newVal) ) 

#define IInterfaceCache_get_DomainHitRate(This,pVal)	\
    ( (This)->lpVtbl -> get_DomainHitRate(This,pVal) ) 

#define IInterfaceCache_get_AccountCacheTTL(This,pVal)	\
    ( (This)->lpVtbl -> get_AccountCacheTTL(This,pVal) ) 

#define IInterfaceCache_put_AccountCacheTTL(This,newVal)	\
    ( (This)->lpVtbl -> put_AccountCacheTTL(This,newVal) ) 

#define IInterfaceCache_get_AccountHitRate(This,pVal)	\
    ( (This)->lpVtbl -> get_AccountHitRate(This,pVal) ) 

#define IInterfaceCache_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IInterfaceCache_get_AliasCacheTTL(This,pVal)	\
    ( (This)->lpVtbl -> get_AliasCacheTTL(This,pVal) ) 

#define IInterfaceCache_put_AliasCacheTTL(This,newVal)	\
    ( (This)->lpVtbl -> put_AliasCacheTTL(This,newVal) ) 

#define IInterfaceCache_get_AliasHitRate(This,pVal)	\
    ( (This)->lpVtbl -> get_AliasHitRate(This,pVal) ) 

#define IInterfaceCache_get_DistributionListCacheTTL(This,pVal)	\
    ( (This)->lpVtbl -> get_DistributionListCacheTTL(This,pVal) ) 

#define IInterfaceCache_put_DistributionListCacheTTL(This,newVal)	\
    ( (This)->lpVtbl -> put_DistributionListCacheTTL(This,newVal) ) 

#define IInterfaceCache_get_DistributionListHitRate(This,pVal)	\
    ( (This)->lpVtbl -> get_DistributionListHitRate(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceCache_INTERFACE_DEFINED__ */


#ifndef __IInterfaceBackupManager_INTERFACE_DEFINED__
#define __IInterfaceBackupManager_INTERFACE_DEFINED__

/* interface IInterfaceBackupManager */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceBackupManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E773E8FC-1C9A-4E96-A73C-CC02E7649637")
    IInterfaceBackupManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartBackup( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadBackup( 
            /* [in] */ BSTR sXMLFile,
            /* [retval][out] */ IInterfaceBackup **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceBackupManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceBackupManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceBackupManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceBackupManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceBackupManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceBackupManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceBackupManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceBackupManager * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartBackup )( 
            IInterfaceBackupManager * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadBackup )( 
            IInterfaceBackupManager * This,
            /* [in] */ BSTR sXMLFile,
            /* [retval][out] */ IInterfaceBackup **pVal);
        
        END_INTERFACE
    } IInterfaceBackupManagerVtbl;

    interface IInterfaceBackupManager
    {
        CONST_VTBL struct IInterfaceBackupManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceBackupManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceBackupManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceBackupManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceBackupManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceBackupManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceBackupManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceBackupManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceBackupManager_StartBackup(This)	\
    ( (This)->lpVtbl -> StartBackup(This) ) 

#define IInterfaceBackupManager_LoadBackup(This,sXMLFile,pVal)	\
    ( (This)->lpVtbl -> LoadBackup(This,sXMLFile,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceBackupManager_INTERFACE_DEFINED__ */


#ifndef __IInterfaceBackupSettings_INTERFACE_DEFINED__
#define __IInterfaceBackupSettings_INTERFACE_DEFINED__

/* interface IInterfaceBackupSettings */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceBackupSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C5559F0-DF3F-43C0-935C-F79D41CF8A5B")
    IInterfaceBackupSettings : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Destination( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Destination( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BackupSettings( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BackupSettings( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BackupDomains( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BackupDomains( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BackupMessages( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BackupMessages( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CompressDestinationFiles( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CompressDestinationFiles( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceBackupSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceBackupSettings * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceBackupSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceBackupSettings * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceBackupSettings * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceBackupSettings * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceBackupSettings * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceBackupSettings * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Destination )( 
            IInterfaceBackupSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Destination )( 
            IInterfaceBackupSettings * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackupSettings )( 
            IInterfaceBackupSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackupSettings )( 
            IInterfaceBackupSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackupDomains )( 
            IInterfaceBackupSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackupDomains )( 
            IInterfaceBackupSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackupMessages )( 
            IInterfaceBackupSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackupMessages )( 
            IInterfaceBackupSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CompressDestinationFiles )( 
            IInterfaceBackupSettings * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CompressDestinationFiles )( 
            IInterfaceBackupSettings * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogFile )( 
            IInterfaceBackupSettings * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IInterfaceBackupSettingsVtbl;

    interface IInterfaceBackupSettings
    {
        CONST_VTBL struct IInterfaceBackupSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceBackupSettings_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceBackupSettings_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceBackupSettings_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceBackupSettings_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceBackupSettings_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceBackupSettings_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceBackupSettings_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceBackupSettings_get_Destination(This,pVal)	\
    ( (This)->lpVtbl -> get_Destination(This,pVal) ) 

#define IInterfaceBackupSettings_put_Destination(This,pVal)	\
    ( (This)->lpVtbl -> put_Destination(This,pVal) ) 

#define IInterfaceBackupSettings_get_BackupSettings(This,pVal)	\
    ( (This)->lpVtbl -> get_BackupSettings(This,pVal) ) 

#define IInterfaceBackupSettings_put_BackupSettings(This,newVal)	\
    ( (This)->lpVtbl -> put_BackupSettings(This,newVal) ) 

#define IInterfaceBackupSettings_get_BackupDomains(This,pVal)	\
    ( (This)->lpVtbl -> get_BackupDomains(This,pVal) ) 

#define IInterfaceBackupSettings_put_BackupDomains(This,newVal)	\
    ( (This)->lpVtbl -> put_BackupDomains(This,newVal) ) 

#define IInterfaceBackupSettings_get_BackupMessages(This,pVal)	\
    ( (This)->lpVtbl -> get_BackupMessages(This,pVal) ) 

#define IInterfaceBackupSettings_put_BackupMessages(This,newVal)	\
    ( (This)->lpVtbl -> put_BackupMessages(This,newVal) ) 

#define IInterfaceBackupSettings_get_CompressDestinationFiles(This,pVal)	\
    ( (This)->lpVtbl -> get_CompressDestinationFiles(This,pVal) ) 

#define IInterfaceBackupSettings_put_CompressDestinationFiles(This,newVal)	\
    ( (This)->lpVtbl -> put_CompressDestinationFiles(This,newVal) ) 

#define IInterfaceBackupSettings_get_LogFile(This,pVal)	\
    ( (This)->lpVtbl -> get_LogFile(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceBackupSettings_INTERFACE_DEFINED__ */


#ifndef __IInterfaceBackup_INTERFACE_DEFINED__
#define __IInterfaceBackup_INTERFACE_DEFINED__

/* interface IInterfaceBackup */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceBackup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BC84454B-FCE1-41FA-A3DD-2C57F61D4310")
    IInterfaceBackup : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartRestore( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ContainsSettings( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ContainsDomains( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ContainsMessages( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RestoreSettings( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RestoreSettings( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RestoreDomains( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RestoreDomains( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RestoreMessages( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RestoreMessages( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceBackupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceBackup * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceBackup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceBackup * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceBackup * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceBackup * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceBackup * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceBackup * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartRestore )( 
            IInterfaceBackup * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContainsSettings )( 
            IInterfaceBackup * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContainsDomains )( 
            IInterfaceBackup * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContainsMessages )( 
            IInterfaceBackup * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RestoreSettings )( 
            IInterfaceBackup * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RestoreSettings )( 
            IInterfaceBackup * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RestoreDomains )( 
            IInterfaceBackup * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RestoreDomains )( 
            IInterfaceBackup * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RestoreMessages )( 
            IInterfaceBackup * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RestoreMessages )( 
            IInterfaceBackup * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        END_INTERFACE
    } IInterfaceBackupVtbl;

    interface IInterfaceBackup
    {
        CONST_VTBL struct IInterfaceBackupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceBackup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceBackup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceBackup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceBackup_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceBackup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceBackup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceBackup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceBackup_StartRestore(This)	\
    ( (This)->lpVtbl -> StartRestore(This) ) 

#define IInterfaceBackup_get_ContainsSettings(This,pVal)	\
    ( (This)->lpVtbl -> get_ContainsSettings(This,pVal) ) 

#define IInterfaceBackup_get_ContainsDomains(This,pVal)	\
    ( (This)->lpVtbl -> get_ContainsDomains(This,pVal) ) 

#define IInterfaceBackup_get_ContainsMessages(This,pVal)	\
    ( (This)->lpVtbl -> get_ContainsMessages(This,pVal) ) 

#define IInterfaceBackup_get_RestoreSettings(This,pVal)	\
    ( (This)->lpVtbl -> get_RestoreSettings(This,pVal) ) 

#define IInterfaceBackup_put_RestoreSettings(This,newVal)	\
    ( (This)->lpVtbl -> put_RestoreSettings(This,newVal) ) 

#define IInterfaceBackup_get_RestoreDomains(This,pVal)	\
    ( (This)->lpVtbl -> get_RestoreDomains(This,pVal) ) 

#define IInterfaceBackup_put_RestoreDomains(This,newVal)	\
    ( (This)->lpVtbl -> put_RestoreDomains(This,newVal) ) 

#define IInterfaceBackup_get_RestoreMessages(This,pVal)	\
    ( (This)->lpVtbl -> get_RestoreMessages(This,pVal) ) 

#define IInterfaceBackup_put_RestoreMessages(This,newVal)	\
    ( (This)->lpVtbl -> put_RestoreMessages(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceBackup_INTERFACE_DEFINED__ */


#ifndef __IInterfaceGlobalObjects_INTERFACE_DEFINED__
#define __IInterfaceGlobalObjects_INTERFACE_DEFINED__

/* interface IInterfaceGlobalObjects */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceGlobalObjects;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F0FE3307-66D9-480D-B1B5-3AF6CD3C0C8A")
    IInterfaceGlobalObjects : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DeliveryQueue( 
            /* [retval][out] */ IInterfaceDeliveryQueue **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Languages( 
            /* [retval][out] */ IInterfaceLanguages **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceGlobalObjectsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceGlobalObjects * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceGlobalObjects * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceGlobalObjects * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceGlobalObjects * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceGlobalObjects * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceGlobalObjects * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceGlobalObjects * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DeliveryQueue )( 
            IInterfaceGlobalObjects * This,
            /* [retval][out] */ IInterfaceDeliveryQueue **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Languages )( 
            IInterfaceGlobalObjects * This,
            /* [retval][out] */ IInterfaceLanguages **pVal);
        
        END_INTERFACE
    } IInterfaceGlobalObjectsVtbl;

    interface IInterfaceGlobalObjects
    {
        CONST_VTBL struct IInterfaceGlobalObjectsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceGlobalObjects_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceGlobalObjects_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceGlobalObjects_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceGlobalObjects_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceGlobalObjects_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceGlobalObjects_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceGlobalObjects_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceGlobalObjects_get_DeliveryQueue(This,pVal)	\
    ( (This)->lpVtbl -> get_DeliveryQueue(This,pVal) ) 

#define IInterfaceGlobalObjects_get_Languages(This,pVal)	\
    ( (This)->lpVtbl -> get_Languages(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceGlobalObjects_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDeliveryQueue_INTERFACE_DEFINED__
#define __IInterfaceDeliveryQueue_INTERFACE_DEFINED__

/* interface IInterfaceDeliveryQueue */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDeliveryQueue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B870F27A-CA77-473C-8106-A9F296F342A5")
    IInterfaceDeliveryQueue : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetDeliveryTime( 
            /* [in] */ hyper iMessageID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartDelivery( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ hyper iMessageID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDeliveryQueueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDeliveryQueue * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDeliveryQueue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDeliveryQueue * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDeliveryQueue * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDeliveryQueue * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDeliveryQueue * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDeliveryQueue * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IInterfaceDeliveryQueue * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetDeliveryTime )( 
            IInterfaceDeliveryQueue * This,
            /* [in] */ hyper iMessageID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartDelivery )( 
            IInterfaceDeliveryQueue * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IInterfaceDeliveryQueue * This,
            /* [in] */ hyper iMessageID);
        
        END_INTERFACE
    } IInterfaceDeliveryQueueVtbl;

    interface IInterfaceDeliveryQueue
    {
        CONST_VTBL struct IInterfaceDeliveryQueueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDeliveryQueue_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDeliveryQueue_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDeliveryQueue_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDeliveryQueue_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDeliveryQueue_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDeliveryQueue_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDeliveryQueue_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDeliveryQueue_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IInterfaceDeliveryQueue_ResetDeliveryTime(This,iMessageID)	\
    ( (This)->lpVtbl -> ResetDeliveryTime(This,iMessageID) ) 

#define IInterfaceDeliveryQueue_StartDelivery(This)	\
    ( (This)->lpVtbl -> StartDelivery(This) ) 

#define IInterfaceDeliveryQueue_Remove(This,iMessageID)	\
    ( (This)->lpVtbl -> Remove(This,iMessageID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDeliveryQueue_INTERFACE_DEFINED__ */


#ifndef __IInterfaceLanguage_INTERFACE_DEFINED__
#define __IInterfaceLanguage_INTERFACE_DEFINED__

/* interface IInterfaceLanguage */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceLanguage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A98C92EF-6AA0-4F22-A29F-BE9154CC242A")
    IInterfaceLanguage : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_String( 
            /* [in] */ BSTR EnglishString,
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsDownloaded( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Download( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceLanguageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceLanguage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceLanguage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceLanguage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceLanguage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceLanguage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceLanguage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceLanguage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_String )( 
            IInterfaceLanguage * This,
            /* [in] */ BSTR EnglishString,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceLanguage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsDownloaded )( 
            IInterfaceLanguage * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Download )( 
            IInterfaceLanguage * This);
        
        END_INTERFACE
    } IInterfaceLanguageVtbl;

    interface IInterfaceLanguage
    {
        CONST_VTBL struct IInterfaceLanguageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceLanguage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceLanguage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceLanguage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceLanguage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceLanguage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceLanguage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceLanguage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceLanguage_get_String(This,EnglishString,pVal)	\
    ( (This)->lpVtbl -> get_String(This,EnglishString,pVal) ) 

#define IInterfaceLanguage_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceLanguage_get_IsDownloaded(This,pVal)	\
    ( (This)->lpVtbl -> get_IsDownloaded(This,pVal) ) 

#define IInterfaceLanguage_Download(This)	\
    ( (This)->lpVtbl -> Download(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceLanguage_INTERFACE_DEFINED__ */


#ifndef __IInterfaceIMAPFolder_INTERFACE_DEFINED__
#define __IInterfaceIMAPFolder_INTERFACE_DEFINED__

/* interface IInterfaceIMAPFolder */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceIMAPFolder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6EB9E09E-EBE2-4BD7-A8C5-3499257DEB0B")
    IInterfaceIMAPFolder : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Subscribed( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Subscribed( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Messages( 
            /* [retval][out] */ IInterfaceMessages **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SubFolders( 
            /* [retval][out] */ IInterfaceIMAPFolders **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ParentID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Permissions( 
            /* [retval][out] */ IInterfaceIMAPFolderPermissions **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CurrentUID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CreationTime( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceIMAPFolderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceIMAPFolder * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceIMAPFolder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceIMAPFolder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceIMAPFolder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceIMAPFolder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceIMAPFolder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceIMAPFolder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceIMAPFolder * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceIMAPFolder * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IInterfaceIMAPFolder * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Subscribed )( 
            IInterfaceIMAPFolder * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Subscribed )( 
            IInterfaceIMAPFolder * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Messages )( 
            IInterfaceIMAPFolder * This,
            /* [retval][out] */ IInterfaceMessages **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SubFolders )( 
            IInterfaceIMAPFolder * This,
            /* [retval][out] */ IInterfaceIMAPFolders **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceIMAPFolder * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ParentID )( 
            IInterfaceIMAPFolder * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Permissions )( 
            IInterfaceIMAPFolder * This,
            /* [retval][out] */ IInterfaceIMAPFolderPermissions **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceIMAPFolder * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CurrentUID )( 
            IInterfaceIMAPFolder * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CreationTime )( 
            IInterfaceIMAPFolder * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IInterfaceIMAPFolderVtbl;

    interface IInterfaceIMAPFolder
    {
        CONST_VTBL struct IInterfaceIMAPFolderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceIMAPFolder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceIMAPFolder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceIMAPFolder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceIMAPFolder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceIMAPFolder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceIMAPFolder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceIMAPFolder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceIMAPFolder_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceIMAPFolder_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceIMAPFolder_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IInterfaceIMAPFolder_get_Subscribed(This,pVal)	\
    ( (This)->lpVtbl -> get_Subscribed(This,pVal) ) 

#define IInterfaceIMAPFolder_put_Subscribed(This,newVal)	\
    ( (This)->lpVtbl -> put_Subscribed(This,newVal) ) 

#define IInterfaceIMAPFolder_get_Messages(This,pVal)	\
    ( (This)->lpVtbl -> get_Messages(This,pVal) ) 

#define IInterfaceIMAPFolder_get_SubFolders(This,pVal)	\
    ( (This)->lpVtbl -> get_SubFolders(This,pVal) ) 

#define IInterfaceIMAPFolder_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceIMAPFolder_get_ParentID(This,pVal)	\
    ( (This)->lpVtbl -> get_ParentID(This,pVal) ) 

#define IInterfaceIMAPFolder_get_Permissions(This,pVal)	\
    ( (This)->lpVtbl -> get_Permissions(This,pVal) ) 

#define IInterfaceIMAPFolder_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IInterfaceIMAPFolder_get_CurrentUID(This,pVal)	\
    ( (This)->lpVtbl -> get_CurrentUID(This,pVal) ) 

#define IInterfaceIMAPFolder_get_CreationTime(This,pVal)	\
    ( (This)->lpVtbl -> get_CreationTime(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceIMAPFolder_INTERFACE_DEFINED__ */


#ifndef __IInterfaceIMAPFolders_INTERFACE_DEFINED__
#define __IInterfaceIMAPFolders_INTERFACE_DEFINED__

/* interface IInterfaceIMAPFolders */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceIMAPFolders;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("328B16A7-8314-4398-B506-90937569EDBA")
    IInterfaceIMAPFolders : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceIMAPFolder **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceIMAPFolder **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByName( 
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceIMAPFolder **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceIMAPFolder **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long lDBID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceIMAPFoldersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceIMAPFolders * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceIMAPFolders * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceIMAPFolders * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceIMAPFolders * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceIMAPFolders * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceIMAPFolders * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceIMAPFolders * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceIMAPFolders * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceIMAPFolder **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceIMAPFolders * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceIMAPFolder **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByName )( 
            IInterfaceIMAPFolders * This,
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceIMAPFolder **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceIMAPFolders * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceIMAPFolders * This,
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceIMAPFolder **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceIMAPFolders * This,
            /* [in] */ long lDBID);
        
        END_INTERFACE
    } IInterfaceIMAPFoldersVtbl;

    interface IInterfaceIMAPFolders
    {
        CONST_VTBL struct IInterfaceIMAPFoldersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceIMAPFolders_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceIMAPFolders_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceIMAPFolders_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceIMAPFolders_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceIMAPFolders_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceIMAPFolders_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceIMAPFolders_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceIMAPFolders_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceIMAPFolders_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceIMAPFolders_get_ItemByName(This,sName,pVal)	\
    ( (This)->lpVtbl -> get_ItemByName(This,sName,pVal) ) 

#define IInterfaceIMAPFolders_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceIMAPFolders_Add(This,sName,pVal)	\
    ( (This)->lpVtbl -> Add(This,sName,pVal) ) 

#define IInterfaceIMAPFolders_DeleteByDBID(This,lDBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,lDBID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceIMAPFolders_INTERFACE_DEFINED__ */


#ifndef __IInterfaceEventLog_INTERFACE_DEFINED__
#define __IInterfaceEventLog_INTERFACE_DEFINED__

/* interface IInterfaceEventLog */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceEventLog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2173A96C-A350-4342-A852-F4A059D7716A")
    IInterfaceEventLog : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Write( 
            BSTR sMessage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceEventLogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceEventLog * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceEventLog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceEventLog * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceEventLog * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceEventLog * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceEventLog * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceEventLog * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Write )( 
            IInterfaceEventLog * This,
            BSTR sMessage);
        
        END_INTERFACE
    } IInterfaceEventLogVtbl;

    interface IInterfaceEventLog
    {
        CONST_VTBL struct IInterfaceEventLogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceEventLog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceEventLog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceEventLog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceEventLog_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceEventLog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceEventLog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceEventLog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceEventLog_Write(This,sMessage)	\
    ( (This)->lpVtbl -> Write(This,sMessage) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceEventLog_INTERFACE_DEFINED__ */


#ifndef __IInterfaceSURBLServers_INTERFACE_DEFINED__
#define __IInterfaceSURBLServers_INTERFACE_DEFINED__

/* interface IInterfaceSURBLServers */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceSURBLServers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D6B91C3A-90C1-4943-B818-EE66119E4702")
    IInterfaceSURBLServers : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceSURBLServer **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceSURBLServer **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceSURBLServer **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDNSHost( 
            /* [in] */ BSTR sDNSHost,
            /* [retval][out] */ IInterfaceSURBLServer **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceSURBLServersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceSURBLServers * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceSURBLServers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceSURBLServers * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceSURBLServers * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceSURBLServers * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceSURBLServers * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceSURBLServers * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceSURBLServers * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceSURBLServer **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceSURBLServers * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceSURBLServers * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceSURBLServers * This,
            /* [retval][out] */ IInterfaceSURBLServer **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceSURBLServers * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceSURBLServer **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceSURBLServers * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDNSHost )( 
            IInterfaceSURBLServers * This,
            /* [in] */ BSTR sDNSHost,
            /* [retval][out] */ IInterfaceSURBLServer **pVal);
        
        END_INTERFACE
    } IInterfaceSURBLServersVtbl;

    interface IInterfaceSURBLServers
    {
        CONST_VTBL struct IInterfaceSURBLServersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceSURBLServers_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceSURBLServers_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceSURBLServers_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceSURBLServers_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceSURBLServers_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceSURBLServers_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceSURBLServers_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceSURBLServers_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceSURBLServers_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceSURBLServers_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceSURBLServers_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceSURBLServers_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceSURBLServers_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceSURBLServers_get_ItemByDNSHost(This,sDNSHost,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDNSHost(This,sDNSHost,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceSURBLServers_INTERFACE_DEFINED__ */


#ifndef __IInterfaceSURBLServer_INTERFACE_DEFINED__
#define __IInterfaceSURBLServer_INTERFACE_DEFINED__

/* interface IInterfaceSURBLServer */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceSURBLServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A4866EDD-F0B8-49C7-A477-57D469F7D7D4")
    IInterfaceSURBLServer : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Active( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Active( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DNSHost( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DNSHost( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RejectMessage( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RejectMessage( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Score( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Score( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceSURBLServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceSURBLServer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceSURBLServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceSURBLServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceSURBLServer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceSURBLServer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceSURBLServer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceSURBLServer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Active )( 
            IInterfaceSURBLServer * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Active )( 
            IInterfaceSURBLServer * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceSURBLServer * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DNSHost )( 
            IInterfaceSURBLServer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DNSHost )( 
            IInterfaceSURBLServer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RejectMessage )( 
            IInterfaceSURBLServer * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RejectMessage )( 
            IInterfaceSURBLServer * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceSURBLServer * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Score )( 
            IInterfaceSURBLServer * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Score )( 
            IInterfaceSURBLServer * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceSURBLServer * This);
        
        END_INTERFACE
    } IInterfaceSURBLServerVtbl;

    interface IInterfaceSURBLServer
    {
        CONST_VTBL struct IInterfaceSURBLServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceSURBLServer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceSURBLServer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceSURBLServer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceSURBLServer_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceSURBLServer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceSURBLServer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceSURBLServer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceSURBLServer_get_Active(This,pVal)	\
    ( (This)->lpVtbl -> get_Active(This,pVal) ) 

#define IInterfaceSURBLServer_put_Active(This,newVal)	\
    ( (This)->lpVtbl -> put_Active(This,newVal) ) 

#define IInterfaceSURBLServer_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceSURBLServer_get_DNSHost(This,pVal)	\
    ( (This)->lpVtbl -> get_DNSHost(This,pVal) ) 

#define IInterfaceSURBLServer_put_DNSHost(This,newVal)	\
    ( (This)->lpVtbl -> put_DNSHost(This,newVal) ) 

#define IInterfaceSURBLServer_get_RejectMessage(This,pVal)	\
    ( (This)->lpVtbl -> get_RejectMessage(This,pVal) ) 

#define IInterfaceSURBLServer_put_RejectMessage(This,newVal)	\
    ( (This)->lpVtbl -> put_RejectMessage(This,newVal) ) 

#define IInterfaceSURBLServer_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceSURBLServer_get_Score(This,pVal)	\
    ( (This)->lpVtbl -> get_Score(This,pVal) ) 

#define IInterfaceSURBLServer_put_Score(This,newVal)	\
    ( (This)->lpVtbl -> put_Score(This,newVal) ) 

#define IInterfaceSURBLServer_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceSURBLServer_INTERFACE_DEFINED__ */


#ifndef __IInterfaceAntiSpam_INTERFACE_DEFINED__
#define __IInterfaceAntiSpam_INTERFACE_DEFINED__

/* interface IInterfaceAntiSpam */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceAntiSpam;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("998A7E66-21FA-47CC-9DB4-81822F2D05C9")
    IInterfaceAntiSpam : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GreyListingEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GreyListingEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GreyListingInitialDelay( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GreyListingInitialDelay( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GreyListingInitialDelete( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GreyListingInitialDelete( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GreyListingFinalDelete( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GreyListingFinalDelete( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SURBLServers( 
            /* [retval][out] */ IInterfaceSURBLServers **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CheckHostInHelo( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CheckHostInHelo( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AddHeaderSpam( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AddHeaderSpam( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AddHeaderReason( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AddHeaderReason( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PrependSubject( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PrependSubject( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PrependSubjectText( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PrependSubjectText( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GreyListingWhiteAddresses( 
            /* [retval][out] */ IInterfaceGreyListingWhiteAddresses **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WhiteListAddresses( 
            /* [retval][out] */ IInterfaceWhiteListAddresses **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CheckHostInHeloScore( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CheckHostInHeloScore( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpamMarkThreshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SpamMarkThreshold( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpamDeleteThreshold( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SpamDeleteThreshold( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseSPF( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseSPF( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseMXChecks( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseMXChecks( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseSPFScore( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseSPFScore( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseMXChecksScore( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseMXChecksScore( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DNSBlackLists( 
            /* [retval][out] */ IInterfaceDNSBlackLists **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TarpitDelay( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TarpitDelay( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TarpitCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TarpitCount( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpamAssassinEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SpamAssassinEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpamAssassinScore( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SpamAssassinScore( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpamAssassinMergeScore( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SpamAssassinMergeScore( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpamAssassinHost( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SpamAssassinHost( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SpamAssassinPort( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SpamAssassinPort( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearGreyListingTriplets( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaximumMessageSize( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaximumMessageSize( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DKIMVerify( 
            /* [in] */ BSTR File,
            /* [retval][out] */ eDKIMResult *pResult) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DKIMVerificationEnabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DKIMVerificationEnabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DKIMVerificationFailureScore( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DKIMVerificationFailureScore( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BypassGreylistingOnSPFSuccess( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BypassGreylistingOnSPFSuccess( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BypassGreylistingOnMailFromMX( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BypassGreylistingOnMailFromMX( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TestSpamAssassinConnection( 
            /* [in] */ BSTR Hostname,
            long Port,
            /* [out] */ BSTR *ResultText,
            /* [retval][out] */ VARIANT_BOOL *pResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceAntiSpamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceAntiSpam * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceAntiSpam * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceAntiSpam * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceAntiSpam * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceAntiSpam * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceAntiSpam * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceAntiSpam * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GreyListingEnabled )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GreyListingEnabled )( 
            IInterfaceAntiSpam * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GreyListingInitialDelay )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GreyListingInitialDelay )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GreyListingInitialDelete )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GreyListingInitialDelete )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GreyListingFinalDelete )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GreyListingFinalDelete )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SURBLServers )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ IInterfaceSURBLServers **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHostInHelo )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CheckHostInHelo )( 
            IInterfaceAntiSpam * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AddHeaderSpam )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AddHeaderSpam )( 
            IInterfaceAntiSpam * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AddHeaderReason )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AddHeaderReason )( 
            IInterfaceAntiSpam * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PrependSubject )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PrependSubject )( 
            IInterfaceAntiSpam * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PrependSubjectText )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PrependSubjectText )( 
            IInterfaceAntiSpam * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GreyListingWhiteAddresses )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ IInterfaceGreyListingWhiteAddresses **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WhiteListAddresses )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ IInterfaceWhiteListAddresses **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CheckHostInHeloScore )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CheckHostInHeloScore )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpamMarkThreshold )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpamMarkThreshold )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpamDeleteThreshold )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpamDeleteThreshold )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseSPF )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseSPF )( 
            IInterfaceAntiSpam * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseMXChecks )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseMXChecks )( 
            IInterfaceAntiSpam * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseSPFScore )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseSPFScore )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseMXChecksScore )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseMXChecksScore )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DNSBlackLists )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ IInterfaceDNSBlackLists **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TarpitDelay )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TarpitDelay )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TarpitCount )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TarpitCount )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpamAssassinEnabled )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpamAssassinEnabled )( 
            IInterfaceAntiSpam * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpamAssassinScore )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpamAssassinScore )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpamAssassinMergeScore )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpamAssassinMergeScore )( 
            IInterfaceAntiSpam * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpamAssassinHost )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpamAssassinHost )( 
            IInterfaceAntiSpam * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpamAssassinPort )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpamAssassinPort )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearGreyListingTriplets )( 
            IInterfaceAntiSpam * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaximumMessageSize )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaximumMessageSize )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DKIMVerify )( 
            IInterfaceAntiSpam * This,
            /* [in] */ BSTR File,
            /* [retval][out] */ eDKIMResult *pResult);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DKIMVerificationEnabled )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DKIMVerificationEnabled )( 
            IInterfaceAntiSpam * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DKIMVerificationFailureScore )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DKIMVerificationFailureScore )( 
            IInterfaceAntiSpam * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BypassGreylistingOnSPFSuccess )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BypassGreylistingOnSPFSuccess )( 
            IInterfaceAntiSpam * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BypassGreylistingOnMailFromMX )( 
            IInterfaceAntiSpam * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BypassGreylistingOnMailFromMX )( 
            IInterfaceAntiSpam * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TestSpamAssassinConnection )( 
            IInterfaceAntiSpam * This,
            /* [in] */ BSTR Hostname,
            long Port,
            /* [out] */ BSTR *ResultText,
            /* [retval][out] */ VARIANT_BOOL *pResult);
        
        END_INTERFACE
    } IInterfaceAntiSpamVtbl;

    interface IInterfaceAntiSpam
    {
        CONST_VTBL struct IInterfaceAntiSpamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceAntiSpam_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceAntiSpam_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceAntiSpam_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceAntiSpam_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceAntiSpam_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceAntiSpam_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceAntiSpam_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceAntiSpam_get_GreyListingEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_GreyListingEnabled(This,pVal) ) 

#define IInterfaceAntiSpam_put_GreyListingEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_GreyListingEnabled(This,newVal) ) 

#define IInterfaceAntiSpam_get_GreyListingInitialDelay(This,pVal)	\
    ( (This)->lpVtbl -> get_GreyListingInitialDelay(This,pVal) ) 

#define IInterfaceAntiSpam_put_GreyListingInitialDelay(This,newVal)	\
    ( (This)->lpVtbl -> put_GreyListingInitialDelay(This,newVal) ) 

#define IInterfaceAntiSpam_get_GreyListingInitialDelete(This,pVal)	\
    ( (This)->lpVtbl -> get_GreyListingInitialDelete(This,pVal) ) 

#define IInterfaceAntiSpam_put_GreyListingInitialDelete(This,newVal)	\
    ( (This)->lpVtbl -> put_GreyListingInitialDelete(This,newVal) ) 

#define IInterfaceAntiSpam_get_GreyListingFinalDelete(This,pVal)	\
    ( (This)->lpVtbl -> get_GreyListingFinalDelete(This,pVal) ) 

#define IInterfaceAntiSpam_put_GreyListingFinalDelete(This,newVal)	\
    ( (This)->lpVtbl -> put_GreyListingFinalDelete(This,newVal) ) 

#define IInterfaceAntiSpam_get_SURBLServers(This,pVal)	\
    ( (This)->lpVtbl -> get_SURBLServers(This,pVal) ) 

#define IInterfaceAntiSpam_get_CheckHostInHelo(This,pVal)	\
    ( (This)->lpVtbl -> get_CheckHostInHelo(This,pVal) ) 

#define IInterfaceAntiSpam_put_CheckHostInHelo(This,newVal)	\
    ( (This)->lpVtbl -> put_CheckHostInHelo(This,newVal) ) 

#define IInterfaceAntiSpam_get_AddHeaderSpam(This,pVal)	\
    ( (This)->lpVtbl -> get_AddHeaderSpam(This,pVal) ) 

#define IInterfaceAntiSpam_put_AddHeaderSpam(This,newVal)	\
    ( (This)->lpVtbl -> put_AddHeaderSpam(This,newVal) ) 

#define IInterfaceAntiSpam_get_AddHeaderReason(This,pVal)	\
    ( (This)->lpVtbl -> get_AddHeaderReason(This,pVal) ) 

#define IInterfaceAntiSpam_put_AddHeaderReason(This,newVal)	\
    ( (This)->lpVtbl -> put_AddHeaderReason(This,newVal) ) 

#define IInterfaceAntiSpam_get_PrependSubject(This,pVal)	\
    ( (This)->lpVtbl -> get_PrependSubject(This,pVal) ) 

#define IInterfaceAntiSpam_put_PrependSubject(This,newVal)	\
    ( (This)->lpVtbl -> put_PrependSubject(This,newVal) ) 

#define IInterfaceAntiSpam_get_PrependSubjectText(This,pVal)	\
    ( (This)->lpVtbl -> get_PrependSubjectText(This,pVal) ) 

#define IInterfaceAntiSpam_put_PrependSubjectText(This,newVal)	\
    ( (This)->lpVtbl -> put_PrependSubjectText(This,newVal) ) 

#define IInterfaceAntiSpam_get_GreyListingWhiteAddresses(This,pVal)	\
    ( (This)->lpVtbl -> get_GreyListingWhiteAddresses(This,pVal) ) 

#define IInterfaceAntiSpam_get_WhiteListAddresses(This,pVal)	\
    ( (This)->lpVtbl -> get_WhiteListAddresses(This,pVal) ) 

#define IInterfaceAntiSpam_get_CheckHostInHeloScore(This,pVal)	\
    ( (This)->lpVtbl -> get_CheckHostInHeloScore(This,pVal) ) 

#define IInterfaceAntiSpam_put_CheckHostInHeloScore(This,newVal)	\
    ( (This)->lpVtbl -> put_CheckHostInHeloScore(This,newVal) ) 

#define IInterfaceAntiSpam_get_SpamMarkThreshold(This,pVal)	\
    ( (This)->lpVtbl -> get_SpamMarkThreshold(This,pVal) ) 

#define IInterfaceAntiSpam_put_SpamMarkThreshold(This,newVal)	\
    ( (This)->lpVtbl -> put_SpamMarkThreshold(This,newVal) ) 

#define IInterfaceAntiSpam_get_SpamDeleteThreshold(This,pVal)	\
    ( (This)->lpVtbl -> get_SpamDeleteThreshold(This,pVal) ) 

#define IInterfaceAntiSpam_put_SpamDeleteThreshold(This,newVal)	\
    ( (This)->lpVtbl -> put_SpamDeleteThreshold(This,newVal) ) 

#define IInterfaceAntiSpam_get_UseSPF(This,pVal)	\
    ( (This)->lpVtbl -> get_UseSPF(This,pVal) ) 

#define IInterfaceAntiSpam_put_UseSPF(This,newVal)	\
    ( (This)->lpVtbl -> put_UseSPF(This,newVal) ) 

#define IInterfaceAntiSpam_get_UseMXChecks(This,pVal)	\
    ( (This)->lpVtbl -> get_UseMXChecks(This,pVal) ) 

#define IInterfaceAntiSpam_put_UseMXChecks(This,newVal)	\
    ( (This)->lpVtbl -> put_UseMXChecks(This,newVal) ) 

#define IInterfaceAntiSpam_get_UseSPFScore(This,pVal)	\
    ( (This)->lpVtbl -> get_UseSPFScore(This,pVal) ) 

#define IInterfaceAntiSpam_put_UseSPFScore(This,newVal)	\
    ( (This)->lpVtbl -> put_UseSPFScore(This,newVal) ) 

#define IInterfaceAntiSpam_get_UseMXChecksScore(This,pVal)	\
    ( (This)->lpVtbl -> get_UseMXChecksScore(This,pVal) ) 

#define IInterfaceAntiSpam_put_UseMXChecksScore(This,newVal)	\
    ( (This)->lpVtbl -> put_UseMXChecksScore(This,newVal) ) 

#define IInterfaceAntiSpam_get_DNSBlackLists(This,pVal)	\
    ( (This)->lpVtbl -> get_DNSBlackLists(This,pVal) ) 

#define IInterfaceAntiSpam_get_TarpitDelay(This,pVal)	\
    ( (This)->lpVtbl -> get_TarpitDelay(This,pVal) ) 

#define IInterfaceAntiSpam_put_TarpitDelay(This,newVal)	\
    ( (This)->lpVtbl -> put_TarpitDelay(This,newVal) ) 

#define IInterfaceAntiSpam_get_TarpitCount(This,pVal)	\
    ( (This)->lpVtbl -> get_TarpitCount(This,pVal) ) 

#define IInterfaceAntiSpam_put_TarpitCount(This,newVal)	\
    ( (This)->lpVtbl -> put_TarpitCount(This,newVal) ) 

#define IInterfaceAntiSpam_get_SpamAssassinEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_SpamAssassinEnabled(This,pVal) ) 

#define IInterfaceAntiSpam_put_SpamAssassinEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_SpamAssassinEnabled(This,newVal) ) 

#define IInterfaceAntiSpam_get_SpamAssassinScore(This,pVal)	\
    ( (This)->lpVtbl -> get_SpamAssassinScore(This,pVal) ) 

#define IInterfaceAntiSpam_put_SpamAssassinScore(This,newVal)	\
    ( (This)->lpVtbl -> put_SpamAssassinScore(This,newVal) ) 

#define IInterfaceAntiSpam_get_SpamAssassinMergeScore(This,pVal)	\
    ( (This)->lpVtbl -> get_SpamAssassinMergeScore(This,pVal) ) 

#define IInterfaceAntiSpam_put_SpamAssassinMergeScore(This,newVal)	\
    ( (This)->lpVtbl -> put_SpamAssassinMergeScore(This,newVal) ) 

#define IInterfaceAntiSpam_get_SpamAssassinHost(This,pVal)	\
    ( (This)->lpVtbl -> get_SpamAssassinHost(This,pVal) ) 

#define IInterfaceAntiSpam_put_SpamAssassinHost(This,newVal)	\
    ( (This)->lpVtbl -> put_SpamAssassinHost(This,newVal) ) 

#define IInterfaceAntiSpam_get_SpamAssassinPort(This,pVal)	\
    ( (This)->lpVtbl -> get_SpamAssassinPort(This,pVal) ) 

#define IInterfaceAntiSpam_put_SpamAssassinPort(This,newVal)	\
    ( (This)->lpVtbl -> put_SpamAssassinPort(This,newVal) ) 

#define IInterfaceAntiSpam_ClearGreyListingTriplets(This)	\
    ( (This)->lpVtbl -> ClearGreyListingTriplets(This) ) 

#define IInterfaceAntiSpam_get_MaximumMessageSize(This,pVal)	\
    ( (This)->lpVtbl -> get_MaximumMessageSize(This,pVal) ) 

#define IInterfaceAntiSpam_put_MaximumMessageSize(This,newVal)	\
    ( (This)->lpVtbl -> put_MaximumMessageSize(This,newVal) ) 

#define IInterfaceAntiSpam_DKIMVerify(This,File,pResult)	\
    ( (This)->lpVtbl -> DKIMVerify(This,File,pResult) ) 

#define IInterfaceAntiSpam_get_DKIMVerificationEnabled(This,pVal)	\
    ( (This)->lpVtbl -> get_DKIMVerificationEnabled(This,pVal) ) 

#define IInterfaceAntiSpam_put_DKIMVerificationEnabled(This,newVal)	\
    ( (This)->lpVtbl -> put_DKIMVerificationEnabled(This,newVal) ) 

#define IInterfaceAntiSpam_get_DKIMVerificationFailureScore(This,pVal)	\
    ( (This)->lpVtbl -> get_DKIMVerificationFailureScore(This,pVal) ) 

#define IInterfaceAntiSpam_put_DKIMVerificationFailureScore(This,newVal)	\
    ( (This)->lpVtbl -> put_DKIMVerificationFailureScore(This,newVal) ) 

#define IInterfaceAntiSpam_get_BypassGreylistingOnSPFSuccess(This,pVal)	\
    ( (This)->lpVtbl -> get_BypassGreylistingOnSPFSuccess(This,pVal) ) 

#define IInterfaceAntiSpam_put_BypassGreylistingOnSPFSuccess(This,newVal)	\
    ( (This)->lpVtbl -> put_BypassGreylistingOnSPFSuccess(This,newVal) ) 

#define IInterfaceAntiSpam_get_BypassGreylistingOnMailFromMX(This,pVal)	\
    ( (This)->lpVtbl -> get_BypassGreylistingOnMailFromMX(This,pVal) ) 

#define IInterfaceAntiSpam_put_BypassGreylistingOnMailFromMX(This,newVal)	\
    ( (This)->lpVtbl -> put_BypassGreylistingOnMailFromMX(This,newVal) ) 

#define IInterfaceAntiSpam_TestSpamAssassinConnection(This,Hostname,Port,ResultText,pResult)	\
    ( (This)->lpVtbl -> TestSpamAssassinConnection(This,Hostname,Port,ResultText,pResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceAntiSpam_INTERFACE_DEFINED__ */


#ifndef __IInterfaceBlockedAttachment_INTERFACE_DEFINED__
#define __IInterfaceBlockedAttachment_INTERFACE_DEFINED__

/* interface IInterfaceBlockedAttachment */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceBlockedAttachment;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BF5CBCFF-CD54-4FAB-AE60-ADFA9C961C1A")
    IInterfaceBlockedAttachment : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Wildcard( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Wildcard( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceBlockedAttachmentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceBlockedAttachment * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceBlockedAttachment * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceBlockedAttachment * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceBlockedAttachment * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceBlockedAttachment * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceBlockedAttachment * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceBlockedAttachment * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceBlockedAttachment * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Wildcard )( 
            IInterfaceBlockedAttachment * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Wildcard )( 
            IInterfaceBlockedAttachment * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceBlockedAttachment * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IInterfaceBlockedAttachment * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            IInterfaceBlockedAttachment * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceBlockedAttachment * This);
        
        END_INTERFACE
    } IInterfaceBlockedAttachmentVtbl;

    interface IInterfaceBlockedAttachment
    {
        CONST_VTBL struct IInterfaceBlockedAttachmentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceBlockedAttachment_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceBlockedAttachment_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceBlockedAttachment_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceBlockedAttachment_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceBlockedAttachment_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceBlockedAttachment_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceBlockedAttachment_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceBlockedAttachment_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceBlockedAttachment_get_Wildcard(This,pVal)	\
    ( (This)->lpVtbl -> get_Wildcard(This,pVal) ) 

#define IInterfaceBlockedAttachment_put_Wildcard(This,newVal)	\
    ( (This)->lpVtbl -> put_Wildcard(This,newVal) ) 

#define IInterfaceBlockedAttachment_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceBlockedAttachment_get_Description(This,pVal)	\
    ( (This)->lpVtbl -> get_Description(This,pVal) ) 

#define IInterfaceBlockedAttachment_put_Description(This,newVal)	\
    ( (This)->lpVtbl -> put_Description(This,newVal) ) 

#define IInterfaceBlockedAttachment_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceBlockedAttachment_INTERFACE_DEFINED__ */


#ifndef __IInterfaceBlockedAttachments_INTERFACE_DEFINED__
#define __IInterfaceBlockedAttachments_INTERFACE_DEFINED__

/* interface IInterfaceBlockedAttachments */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceBlockedAttachments;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8979F461-AD9D-49E8-8068-BBAB43FBA31A")
    IInterfaceBlockedAttachments : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceBlockedAttachment **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceBlockedAttachment **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceBlockedAttachment **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceBlockedAttachmentsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceBlockedAttachments * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceBlockedAttachments * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceBlockedAttachments * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceBlockedAttachments * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceBlockedAttachments * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceBlockedAttachments * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceBlockedAttachments * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceBlockedAttachments * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceBlockedAttachment **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceBlockedAttachments * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceBlockedAttachments * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceBlockedAttachments * This,
            /* [retval][out] */ IInterfaceBlockedAttachment **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceBlockedAttachments * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceBlockedAttachment **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceBlockedAttachments * This);
        
        END_INTERFACE
    } IInterfaceBlockedAttachmentsVtbl;

    interface IInterfaceBlockedAttachments
    {
        CONST_VTBL struct IInterfaceBlockedAttachmentsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceBlockedAttachments_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceBlockedAttachments_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceBlockedAttachments_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceBlockedAttachments_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceBlockedAttachments_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceBlockedAttachments_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceBlockedAttachments_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceBlockedAttachments_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceBlockedAttachments_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceBlockedAttachments_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceBlockedAttachments_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceBlockedAttachments_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceBlockedAttachments_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceBlockedAttachments_INTERFACE_DEFINED__ */


#ifndef __IInterfaceServerMessages_INTERFACE_DEFINED__
#define __IInterfaceServerMessages_INTERFACE_DEFINED__

/* interface IInterfaceServerMessages */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceServerMessages;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0E90D7D8-0144-4021-9240-8CB9CC6F7628")
    IInterfaceServerMessages : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceServerMessage **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceServerMessage **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByName( 
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceServerMessage **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceServerMessagesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceServerMessages * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceServerMessages * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceServerMessages * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceServerMessages * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceServerMessages * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceServerMessages * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceServerMessages * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceServerMessages * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceServerMessage **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceServerMessages * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceServerMessages * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceServerMessage **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByName )( 
            IInterfaceServerMessages * This,
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceServerMessage **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceServerMessages * This);
        
        END_INTERFACE
    } IInterfaceServerMessagesVtbl;

    interface IInterfaceServerMessages
    {
        CONST_VTBL struct IInterfaceServerMessagesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceServerMessages_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceServerMessages_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceServerMessages_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceServerMessages_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceServerMessages_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceServerMessages_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceServerMessages_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceServerMessages_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceServerMessages_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceServerMessages_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceServerMessages_get_ItemByName(This,sName,pVal)	\
    ( (This)->lpVtbl -> get_ItemByName(This,sName,pVal) ) 

#define IInterfaceServerMessages_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceServerMessages_INTERFACE_DEFINED__ */


#ifndef __IInterfaceServerMessage_INTERFACE_DEFINED__
#define __IInterfaceServerMessage_INTERFACE_DEFINED__

/* interface IInterfaceServerMessage */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceServerMessage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6F7C0387-1AC5-466B-9068-67D659D57A86")
    IInterfaceServerMessage : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceServerMessageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceServerMessage * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceServerMessage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceServerMessage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceServerMessage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceServerMessage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceServerMessage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceServerMessage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceServerMessage * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceServerMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IInterfaceServerMessage * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceServerMessage * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Text )( 
            IInterfaceServerMessage * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Text )( 
            IInterfaceServerMessage * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IInterfaceServerMessageVtbl;

    interface IInterfaceServerMessage
    {
        CONST_VTBL struct IInterfaceServerMessageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceServerMessage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceServerMessage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceServerMessage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceServerMessage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceServerMessage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceServerMessage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceServerMessage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceServerMessage_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceServerMessage_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceServerMessage_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IInterfaceServerMessage_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceServerMessage_get_Text(This,pVal)	\
    ( (This)->lpVtbl -> get_Text(This,pVal) ) 

#define IInterfaceServerMessage_put_Text(This,newVal)	\
    ( (This)->lpVtbl -> put_Text(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceServerMessage_INTERFACE_DEFINED__ */


#ifndef __IInterfaceGreyListingWhiteAddresses_INTERFACE_DEFINED__
#define __IInterfaceGreyListingWhiteAddresses_INTERFACE_DEFINED__

/* interface IInterfaceGreyListingWhiteAddresses */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceGreyListingWhiteAddresses;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D8D54486-4CC5-4240-A4BF-DD68D9C3E85B")
    IInterfaceGreyListingWhiteAddresses : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceGreyListingWhiteAddress **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceGreyListingWhiteAddress **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceGreyListingWhiteAddress **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByName( 
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceGreyListingWhiteAddress **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceGreyListingWhiteAddressesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceGreyListingWhiteAddresses * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceGreyListingWhiteAddresses * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceGreyListingWhiteAddresses * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceGreyListingWhiteAddresses * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceGreyListingWhiteAddresses * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceGreyListingWhiteAddresses * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceGreyListingWhiteAddresses * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceGreyListingWhiteAddresses * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceGreyListingWhiteAddress **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceGreyListingWhiteAddresses * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceGreyListingWhiteAddresses * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceGreyListingWhiteAddresses * This,
            /* [retval][out] */ IInterfaceGreyListingWhiteAddress **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceGreyListingWhiteAddresses * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceGreyListingWhiteAddress **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceGreyListingWhiteAddresses * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByName )( 
            IInterfaceGreyListingWhiteAddresses * This,
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceGreyListingWhiteAddress **pVal);
        
        END_INTERFACE
    } IInterfaceGreyListingWhiteAddressesVtbl;

    interface IInterfaceGreyListingWhiteAddresses
    {
        CONST_VTBL struct IInterfaceGreyListingWhiteAddressesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceGreyListingWhiteAddresses_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceGreyListingWhiteAddresses_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceGreyListingWhiteAddresses_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceGreyListingWhiteAddresses_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceGreyListingWhiteAddresses_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceGreyListingWhiteAddresses_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceGreyListingWhiteAddresses_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceGreyListingWhiteAddresses_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceGreyListingWhiteAddresses_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceGreyListingWhiteAddresses_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceGreyListingWhiteAddresses_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceGreyListingWhiteAddresses_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceGreyListingWhiteAddresses_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceGreyListingWhiteAddresses_get_ItemByName(This,sName,pVal)	\
    ( (This)->lpVtbl -> get_ItemByName(This,sName,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceGreyListingWhiteAddresses_INTERFACE_DEFINED__ */


#ifndef __IInterfaceGreyListingWhiteAddress_INTERFACE_DEFINED__
#define __IInterfaceGreyListingWhiteAddress_INTERFACE_DEFINED__

/* interface IInterfaceGreyListingWhiteAddress */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceGreyListingWhiteAddress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A32DF62B-043F-4C0D-81E9-F4CC3CB62F33")
    IInterfaceGreyListingWhiteAddress : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IPAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IPAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceGreyListingWhiteAddressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceGreyListingWhiteAddress * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceGreyListingWhiteAddress * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceGreyListingWhiteAddress * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceGreyListingWhiteAddress * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceGreyListingWhiteAddress * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceGreyListingWhiteAddress * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceGreyListingWhiteAddress * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceGreyListingWhiteAddress * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IPAddress )( 
            IInterfaceGreyListingWhiteAddress * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_IPAddress )( 
            IInterfaceGreyListingWhiteAddress * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IInterfaceGreyListingWhiteAddress * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            IInterfaceGreyListingWhiteAddress * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceGreyListingWhiteAddress * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceGreyListingWhiteAddress * This);
        
        END_INTERFACE
    } IInterfaceGreyListingWhiteAddressVtbl;

    interface IInterfaceGreyListingWhiteAddress
    {
        CONST_VTBL struct IInterfaceGreyListingWhiteAddressVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceGreyListingWhiteAddress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceGreyListingWhiteAddress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceGreyListingWhiteAddress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceGreyListingWhiteAddress_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceGreyListingWhiteAddress_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceGreyListingWhiteAddress_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceGreyListingWhiteAddress_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceGreyListingWhiteAddress_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceGreyListingWhiteAddress_get_IPAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_IPAddress(This,pVal) ) 

#define IInterfaceGreyListingWhiteAddress_put_IPAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_IPAddress(This,newVal) ) 

#define IInterfaceGreyListingWhiteAddress_get_Description(This,pVal)	\
    ( (This)->lpVtbl -> get_Description(This,pVal) ) 

#define IInterfaceGreyListingWhiteAddress_put_Description(This,newVal)	\
    ( (This)->lpVtbl -> put_Description(This,newVal) ) 

#define IInterfaceGreyListingWhiteAddress_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceGreyListingWhiteAddress_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceGreyListingWhiteAddress_INTERFACE_DEFINED__ */


#ifndef __IInterfaceTCPIPPorts_INTERFACE_DEFINED__
#define __IInterfaceTCPIPPorts_INTERFACE_DEFINED__

/* interface IInterfaceTCPIPPorts */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceTCPIPPorts;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("70471130-C8FA-4218-B68A-F1C9AD973FF6")
    IInterfaceTCPIPPorts : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceTCPIPPort **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceTCPIPPort **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceTCPIPPort **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDefault( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceTCPIPPortsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceTCPIPPorts * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceTCPIPPorts * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceTCPIPPorts * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceTCPIPPorts * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceTCPIPPorts * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceTCPIPPorts * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceTCPIPPorts * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceTCPIPPorts * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceTCPIPPort **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceTCPIPPorts * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceTCPIPPorts * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceTCPIPPorts * This,
            /* [retval][out] */ IInterfaceTCPIPPort **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceTCPIPPorts * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceTCPIPPort **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceTCPIPPorts * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDefault )( 
            IInterfaceTCPIPPorts * This);
        
        END_INTERFACE
    } IInterfaceTCPIPPortsVtbl;

    interface IInterfaceTCPIPPorts
    {
        CONST_VTBL struct IInterfaceTCPIPPortsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceTCPIPPorts_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceTCPIPPorts_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceTCPIPPorts_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceTCPIPPorts_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceTCPIPPorts_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceTCPIPPorts_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceTCPIPPorts_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceTCPIPPorts_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceTCPIPPorts_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceTCPIPPorts_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceTCPIPPorts_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceTCPIPPorts_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceTCPIPPorts_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceTCPIPPorts_SetDefault(This)	\
    ( (This)->lpVtbl -> SetDefault(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceTCPIPPorts_INTERFACE_DEFINED__ */


#ifndef __IInterfaceTCPIPPort_INTERFACE_DEFINED__
#define __IInterfaceTCPIPPort_INTERFACE_DEFINED__

/* interface IInterfaceTCPIPPort */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceTCPIPPort;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5F46B580-89DA-44A3-9518-AEEEDB80F6D7")
    IInterfaceTCPIPPort : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Protocol( 
            /* [retval][out] */ eSessionType *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Protocol( 
            /* [in] */ eSessionType newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PortNumber( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PortNumber( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Address( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Address( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseSSL( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseSSL( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SSLCertificateID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SSLCertificateID( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceTCPIPPortVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceTCPIPPort * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceTCPIPPort * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceTCPIPPort * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceTCPIPPort * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceTCPIPPort * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceTCPIPPort * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceTCPIPPort * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceTCPIPPort * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Protocol )( 
            IInterfaceTCPIPPort * This,
            /* [retval][out] */ eSessionType *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Protocol )( 
            IInterfaceTCPIPPort * This,
            /* [in] */ eSessionType newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PortNumber )( 
            IInterfaceTCPIPPort * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PortNumber )( 
            IInterfaceTCPIPPort * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceTCPIPPort * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Address )( 
            IInterfaceTCPIPPort * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Address )( 
            IInterfaceTCPIPPort * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UseSSL )( 
            IInterfaceTCPIPPort * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UseSSL )( 
            IInterfaceTCPIPPort * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SSLCertificateID )( 
            IInterfaceTCPIPPort * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SSLCertificateID )( 
            IInterfaceTCPIPPort * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceTCPIPPort * This);
        
        END_INTERFACE
    } IInterfaceTCPIPPortVtbl;

    interface IInterfaceTCPIPPort
    {
        CONST_VTBL struct IInterfaceTCPIPPortVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceTCPIPPort_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceTCPIPPort_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceTCPIPPort_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceTCPIPPort_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceTCPIPPort_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceTCPIPPort_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceTCPIPPort_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceTCPIPPort_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceTCPIPPort_get_Protocol(This,pVal)	\
    ( (This)->lpVtbl -> get_Protocol(This,pVal) ) 

#define IInterfaceTCPIPPort_put_Protocol(This,newVal)	\
    ( (This)->lpVtbl -> put_Protocol(This,newVal) ) 

#define IInterfaceTCPIPPort_get_PortNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_PortNumber(This,pVal) ) 

#define IInterfaceTCPIPPort_put_PortNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_PortNumber(This,newVal) ) 

#define IInterfaceTCPIPPort_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceTCPIPPort_get_Address(This,pVal)	\
    ( (This)->lpVtbl -> get_Address(This,pVal) ) 

#define IInterfaceTCPIPPort_put_Address(This,newVal)	\
    ( (This)->lpVtbl -> put_Address(This,newVal) ) 

#define IInterfaceTCPIPPort_get_UseSSL(This,pVal)	\
    ( (This)->lpVtbl -> get_UseSSL(This,pVal) ) 

#define IInterfaceTCPIPPort_put_UseSSL(This,newVal)	\
    ( (This)->lpVtbl -> put_UseSSL(This,newVal) ) 

#define IInterfaceTCPIPPort_get_SSLCertificateID(This,pVal)	\
    ( (This)->lpVtbl -> get_SSLCertificateID(This,pVal) ) 

#define IInterfaceTCPIPPort_put_SSLCertificateID(This,newVal)	\
    ( (This)->lpVtbl -> put_SSLCertificateID(This,newVal) ) 

#define IInterfaceTCPIPPort_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceTCPIPPort_INTERFACE_DEFINED__ */


#ifndef __IInterfaceWhiteListAddresses_INTERFACE_DEFINED__
#define __IInterfaceWhiteListAddresses_INTERFACE_DEFINED__

/* interface IInterfaceWhiteListAddresses */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceWhiteListAddresses;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8492EE2E-7332-4253-B93E-D8B011B47D78")
    IInterfaceWhiteListAddresses : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceWhiteListAddress **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceWhiteListAddress **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceWhiteListAddress **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceWhiteListAddressesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceWhiteListAddresses * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceWhiteListAddresses * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceWhiteListAddresses * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceWhiteListAddresses * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceWhiteListAddresses * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceWhiteListAddresses * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceWhiteListAddresses * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceWhiteListAddresses * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceWhiteListAddress **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceWhiteListAddresses * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceWhiteListAddresses * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceWhiteListAddresses * This,
            /* [retval][out] */ IInterfaceWhiteListAddress **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceWhiteListAddresses * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceWhiteListAddress **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceWhiteListAddresses * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IInterfaceWhiteListAddresses * This);
        
        END_INTERFACE
    } IInterfaceWhiteListAddressesVtbl;

    interface IInterfaceWhiteListAddresses
    {
        CONST_VTBL struct IInterfaceWhiteListAddressesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceWhiteListAddresses_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceWhiteListAddresses_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceWhiteListAddresses_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceWhiteListAddresses_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceWhiteListAddresses_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceWhiteListAddresses_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceWhiteListAddresses_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceWhiteListAddresses_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceWhiteListAddresses_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceWhiteListAddresses_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceWhiteListAddresses_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceWhiteListAddresses_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceWhiteListAddresses_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceWhiteListAddresses_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceWhiteListAddresses_INTERFACE_DEFINED__ */


#ifndef __IInterfaceWhiteListAddress_INTERFACE_DEFINED__
#define __IInterfaceWhiteListAddress_INTERFACE_DEFINED__

/* interface IInterfaceWhiteListAddress */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceWhiteListAddress;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D67457A7-3500-481F-900F-C9741C89D6AB")
    IInterfaceWhiteListAddress : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LowerIPAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LowerIPAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UpperIPAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UpperIPAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EmailAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EmailAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceWhiteListAddressVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceWhiteListAddress * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceWhiteListAddress * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceWhiteListAddress * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceWhiteListAddress * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceWhiteListAddress * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceWhiteListAddress * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceWhiteListAddress * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceWhiteListAddress * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LowerIPAddress )( 
            IInterfaceWhiteListAddress * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LowerIPAddress )( 
            IInterfaceWhiteListAddress * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UpperIPAddress )( 
            IInterfaceWhiteListAddress * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UpperIPAddress )( 
            IInterfaceWhiteListAddress * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EmailAddress )( 
            IInterfaceWhiteListAddress * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EmailAddress )( 
            IInterfaceWhiteListAddress * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IInterfaceWhiteListAddress * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            IInterfaceWhiteListAddress * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceWhiteListAddress * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceWhiteListAddress * This);
        
        END_INTERFACE
    } IInterfaceWhiteListAddressVtbl;

    interface IInterfaceWhiteListAddress
    {
        CONST_VTBL struct IInterfaceWhiteListAddressVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceWhiteListAddress_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceWhiteListAddress_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceWhiteListAddress_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceWhiteListAddress_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceWhiteListAddress_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceWhiteListAddress_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceWhiteListAddress_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceWhiteListAddress_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceWhiteListAddress_get_LowerIPAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_LowerIPAddress(This,pVal) ) 

#define IInterfaceWhiteListAddress_put_LowerIPAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_LowerIPAddress(This,newVal) ) 

#define IInterfaceWhiteListAddress_get_UpperIPAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_UpperIPAddress(This,pVal) ) 

#define IInterfaceWhiteListAddress_put_UpperIPAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_UpperIPAddress(This,newVal) ) 

#define IInterfaceWhiteListAddress_get_EmailAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_EmailAddress(This,pVal) ) 

#define IInterfaceWhiteListAddress_put_EmailAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_EmailAddress(This,newVal) ) 

#define IInterfaceWhiteListAddress_get_Description(This,pVal)	\
    ( (This)->lpVtbl -> get_Description(This,pVal) ) 

#define IInterfaceWhiteListAddress_put_Description(This,newVal)	\
    ( (This)->lpVtbl -> put_Description(This,newVal) ) 

#define IInterfaceWhiteListAddress_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceWhiteListAddress_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceWhiteListAddress_INTERFACE_DEFINED__ */


#ifndef __IInterfaceMessageHeader_INTERFACE_DEFINED__
#define __IInterfaceMessageHeader_INTERFACE_DEFINED__

/* interface IInterfaceMessageHeader */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceMessageHeader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FF69E250-CBFD-4AB6-9440-39599478365D")
    IInterfaceMessageHeader : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceMessageHeaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceMessageHeader * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceMessageHeader * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceMessageHeader * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceMessageHeader * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceMessageHeader * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceMessageHeader * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceMessageHeader * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceMessageHeader * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IInterfaceMessageHeader * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IInterfaceMessageHeader * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IInterfaceMessageHeader * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceMessageHeader * This);
        
        END_INTERFACE
    } IInterfaceMessageHeaderVtbl;

    interface IInterfaceMessageHeader
    {
        CONST_VTBL struct IInterfaceMessageHeaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceMessageHeader_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceMessageHeader_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceMessageHeader_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceMessageHeader_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceMessageHeader_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceMessageHeader_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceMessageHeader_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceMessageHeader_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceMessageHeader_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IInterfaceMessageHeader_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#define IInterfaceMessageHeader_put_Value(This,newVal)	\
    ( (This)->lpVtbl -> put_Value(This,newVal) ) 

#define IInterfaceMessageHeader_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceMessageHeader_INTERFACE_DEFINED__ */


#ifndef __IInterfaceMessageHeaders_INTERFACE_DEFINED__
#define __IInterfaceMessageHeaders_INTERFACE_DEFINED__

/* interface IInterfaceMessageHeaders */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceMessageHeaders;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1ADE0B5E-536C-4707-8385-32A7F6F92500")
    IInterfaceMessageHeaders : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceMessageHeader **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByName( 
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceMessageHeader **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceMessageHeadersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceMessageHeaders * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceMessageHeaders * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceMessageHeaders * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceMessageHeaders * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceMessageHeaders * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceMessageHeaders * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceMessageHeaders * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceMessageHeaders * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceMessageHeader **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceMessageHeaders * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByName )( 
            IInterfaceMessageHeaders * This,
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceMessageHeader **pVal);
        
        END_INTERFACE
    } IInterfaceMessageHeadersVtbl;

    interface IInterfaceMessageHeaders
    {
        CONST_VTBL struct IInterfaceMessageHeadersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceMessageHeaders_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceMessageHeaders_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceMessageHeaders_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceMessageHeaders_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceMessageHeaders_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceMessageHeaders_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceMessageHeaders_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceMessageHeaders_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceMessageHeaders_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceMessageHeaders_get_ItemByName(This,sName,pVal)	\
    ( (This)->lpVtbl -> get_ItemByName(This,sName,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceMessageHeaders_INTERFACE_DEFINED__ */


#ifndef __IInterfaceSSLCertificate_INTERFACE_DEFINED__
#define __IInterfaceSSLCertificate_INTERFACE_DEFINED__

/* interface IInterfaceSSLCertificate */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceSSLCertificate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5CB10D83-8FDA-461B-AD5B-3CBBF9476FD6")
    IInterfaceSSLCertificate : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CertificateFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CertificateFile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PrivateKeyFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PrivateKeyFile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceSSLCertificateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceSSLCertificate * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceSSLCertificate * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceSSLCertificate * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceSSLCertificate * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceSSLCertificate * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceSSLCertificate * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceSSLCertificate * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceSSLCertificate * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceSSLCertificate * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IInterfaceSSLCertificate * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceSSLCertificate * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CertificateFile )( 
            IInterfaceSSLCertificate * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CertificateFile )( 
            IInterfaceSSLCertificate * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PrivateKeyFile )( 
            IInterfaceSSLCertificate * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PrivateKeyFile )( 
            IInterfaceSSLCertificate * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceSSLCertificate * This);
        
        END_INTERFACE
    } IInterfaceSSLCertificateVtbl;

    interface IInterfaceSSLCertificate
    {
        CONST_VTBL struct IInterfaceSSLCertificateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceSSLCertificate_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceSSLCertificate_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceSSLCertificate_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceSSLCertificate_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceSSLCertificate_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceSSLCertificate_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceSSLCertificate_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceSSLCertificate_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceSSLCertificate_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceSSLCertificate_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IInterfaceSSLCertificate_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceSSLCertificate_get_CertificateFile(This,pVal)	\
    ( (This)->lpVtbl -> get_CertificateFile(This,pVal) ) 

#define IInterfaceSSLCertificate_put_CertificateFile(This,newVal)	\
    ( (This)->lpVtbl -> put_CertificateFile(This,newVal) ) 

#define IInterfaceSSLCertificate_get_PrivateKeyFile(This,pVal)	\
    ( (This)->lpVtbl -> get_PrivateKeyFile(This,pVal) ) 

#define IInterfaceSSLCertificate_put_PrivateKeyFile(This,newVal)	\
    ( (This)->lpVtbl -> put_PrivateKeyFile(This,newVal) ) 

#define IInterfaceSSLCertificate_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceSSLCertificate_INTERFACE_DEFINED__ */


#ifndef __IInterfaceSSLCertificates_INTERFACE_DEFINED__
#define __IInterfaceSSLCertificates_INTERFACE_DEFINED__

/* interface IInterfaceSSLCertificates */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceSSLCertificates;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6C0B92B-3973-4E0A-86CB-440AD6C80B71")
    IInterfaceSSLCertificates : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceSSLCertificate **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceSSLCertificate **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceSSLCertificate **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceSSLCertificatesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceSSLCertificates * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceSSLCertificates * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceSSLCertificates * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceSSLCertificates * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceSSLCertificates * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceSSLCertificates * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceSSLCertificates * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceSSLCertificates * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceSSLCertificate **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceSSLCertificates * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceSSLCertificates * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceSSLCertificates * This,
            /* [retval][out] */ IInterfaceSSLCertificate **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceSSLCertificates * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceSSLCertificate **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceSSLCertificates * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IInterfaceSSLCertificates * This);
        
        END_INTERFACE
    } IInterfaceSSLCertificatesVtbl;

    interface IInterfaceSSLCertificates
    {
        CONST_VTBL struct IInterfaceSSLCertificatesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceSSLCertificates_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceSSLCertificates_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceSSLCertificates_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceSSLCertificates_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceSSLCertificates_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceSSLCertificates_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceSSLCertificates_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceSSLCertificates_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceSSLCertificates_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceSSLCertificates_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceSSLCertificates_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceSSLCertificates_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceSSLCertificates_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceSSLCertificates_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceSSLCertificates_INTERFACE_DEFINED__ */


#ifndef __IInterfaceGroups_INTERFACE_DEFINED__
#define __IInterfaceGroups_INTERFACE_DEFINED__

/* interface IInterfaceGroups */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceGroups;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("04B3AAAA-2B86-4C71-8A92-2D174055E1F1")
    IInterfaceGroups : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceGroup **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceGroup **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceGroup **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByName( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ IInterfaceGroup **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceGroupsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceGroups * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceGroups * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceGroups * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceGroups * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceGroups * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceGroups * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceGroups * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceGroups * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceGroup **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceGroups * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceGroups * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceGroups * This,
            /* [retval][out] */ IInterfaceGroup **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceGroups * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceGroup **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByName )( 
            IInterfaceGroups * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IInterfaceGroup **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceGroups * This);
        
        END_INTERFACE
    } IInterfaceGroupsVtbl;

    interface IInterfaceGroups
    {
        CONST_VTBL struct IInterfaceGroupsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceGroups_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceGroups_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceGroups_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceGroups_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceGroups_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceGroups_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceGroups_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceGroups_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceGroups_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceGroups_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceGroups_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceGroups_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceGroups_get_ItemByName(This,Name,pVal)	\
    ( (This)->lpVtbl -> get_ItemByName(This,Name,pVal) ) 

#define IInterfaceGroups_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceGroups_INTERFACE_DEFINED__ */


#ifndef __IInterfaceGroup_INTERFACE_DEFINED__
#define __IInterfaceGroup_INTERFACE_DEFINED__

/* interface IInterfaceGroup */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("096BA43E-55DA-44BD-A5AD-693DA54222ED")
    IInterfaceGroup : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR sVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Members( 
            /* [retval][out] */ IInterfaceGroupMembers **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceGroup * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceGroup * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceGroup * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceGroup * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceGroup * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceGroup * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceGroup * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceGroup * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceGroup * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IInterfaceGroup * This,
            /* [in] */ BSTR sVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Members )( 
            IInterfaceGroup * This,
            /* [retval][out] */ IInterfaceGroupMembers **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceGroup * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceGroup * This);
        
        END_INTERFACE
    } IInterfaceGroupVtbl;

    interface IInterfaceGroup
    {
        CONST_VTBL struct IInterfaceGroupVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceGroup_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceGroup_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceGroup_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceGroup_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceGroup_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceGroup_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceGroup_put_Name(This,sVal)	\
    ( (This)->lpVtbl -> put_Name(This,sVal) ) 

#define IInterfaceGroup_get_Members(This,pVal)	\
    ( (This)->lpVtbl -> get_Members(This,pVal) ) 

#define IInterfaceGroup_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceGroup_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceGroup_INTERFACE_DEFINED__ */


#ifndef __IInterfaceGroupMembers_INTERFACE_DEFINED__
#define __IInterfaceGroupMembers_INTERFACE_DEFINED__

/* interface IInterfaceGroupMembers */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceGroupMembers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9002BDC6-BCA1-4F37-821C-AE6A70D3046E")
    IInterfaceGroupMembers : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceGroupMember **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceGroupMember **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceGroupMember **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceGroupMembersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceGroupMembers * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceGroupMembers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceGroupMembers * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceGroupMembers * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceGroupMembers * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceGroupMembers * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceGroupMembers * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceGroupMembers * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceGroupMember **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceGroupMembers * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceGroupMembers * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceGroupMembers * This,
            /* [retval][out] */ IInterfaceGroupMember **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceGroupMembers * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceGroupMember **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceGroupMembers * This);
        
        END_INTERFACE
    } IInterfaceGroupMembersVtbl;

    interface IInterfaceGroupMembers
    {
        CONST_VTBL struct IInterfaceGroupMembersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceGroupMembers_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceGroupMembers_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceGroupMembers_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceGroupMembers_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceGroupMembers_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceGroupMembers_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceGroupMembers_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceGroupMembers_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceGroupMembers_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceGroupMembers_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceGroupMembers_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceGroupMembers_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceGroupMembers_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceGroupMembers_INTERFACE_DEFINED__ */


#ifndef __IInterfaceGroupMember_INTERFACE_DEFINED__
#define __IInterfaceGroupMember_INTERFACE_DEFINED__

/* interface IInterfaceGroupMember */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceGroupMember;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EF796379-7192-43CD-B4A5-58E44A4A5B7D")
    IInterfaceGroupMember : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GroupID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GroupID( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AccountID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AccountID( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Account( 
            /* [retval][out] */ IInterfaceAccount **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceGroupMemberVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceGroupMember * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceGroupMember * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceGroupMember * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceGroupMember * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceGroupMember * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceGroupMember * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceGroupMember * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceGroupMember * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GroupID )( 
            IInterfaceGroupMember * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GroupID )( 
            IInterfaceGroupMember * This,
            /* [in] */ long pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AccountID )( 
            IInterfaceGroupMember * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AccountID )( 
            IInterfaceGroupMember * This,
            /* [in] */ long pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceGroupMember * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceGroupMember * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Account )( 
            IInterfaceGroupMember * This,
            /* [retval][out] */ IInterfaceAccount **pVal);
        
        END_INTERFACE
    } IInterfaceGroupMemberVtbl;

    interface IInterfaceGroupMember
    {
        CONST_VTBL struct IInterfaceGroupMemberVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceGroupMember_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceGroupMember_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceGroupMember_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceGroupMember_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceGroupMember_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceGroupMember_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceGroupMember_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceGroupMember_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceGroupMember_get_GroupID(This,pVal)	\
    ( (This)->lpVtbl -> get_GroupID(This,pVal) ) 

#define IInterfaceGroupMember_put_GroupID(This,pVal)	\
    ( (This)->lpVtbl -> put_GroupID(This,pVal) ) 

#define IInterfaceGroupMember_get_AccountID(This,pVal)	\
    ( (This)->lpVtbl -> get_AccountID(This,pVal) ) 

#define IInterfaceGroupMember_put_AccountID(This,pVal)	\
    ( (This)->lpVtbl -> put_AccountID(This,pVal) ) 

#define IInterfaceGroupMember_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceGroupMember_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IInterfaceGroupMember_get_Account(This,pVal)	\
    ( (This)->lpVtbl -> get_Account(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceGroupMember_INTERFACE_DEFINED__ */


#ifndef __IInterfaceIMAPFolderPermission_INTERFACE_DEFINED__
#define __IInterfaceIMAPFolderPermission_INTERFACE_DEFINED__

/* interface IInterfaceIMAPFolderPermission */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceIMAPFolderPermission;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A951C988-0D2C-42CA-A9D3-FE7A78F1AB25")
    IInterfaceIMAPFolderPermission : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShareFolderID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PermissionType( 
            /* [retval][out] */ eACLPermissionType *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PermissionType( 
            /* [in] */ eACLPermissionType newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PermissionGroupID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PermissionGroupID( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PermissionAccountID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PermissionAccountID( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Permission( 
            /* [in] */ eACLPermission iType,
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Permission( 
            /* [in] */ eACLPermission iType,
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Account( 
            /* [retval][out] */ IInterfaceAccount **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Group( 
            /* [retval][out] */ IInterfaceGroup **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceIMAPFolderPermissionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceIMAPFolderPermission * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceIMAPFolderPermission * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceIMAPFolderPermission * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceIMAPFolderPermission * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceIMAPFolderPermission * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceIMAPFolderPermission * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceIMAPFolderPermission * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceIMAPFolderPermission * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShareFolderID )( 
            IInterfaceIMAPFolderPermission * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PermissionType )( 
            IInterfaceIMAPFolderPermission * This,
            /* [retval][out] */ eACLPermissionType *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PermissionType )( 
            IInterfaceIMAPFolderPermission * This,
            /* [in] */ eACLPermissionType newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PermissionGroupID )( 
            IInterfaceIMAPFolderPermission * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PermissionGroupID )( 
            IInterfaceIMAPFolderPermission * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PermissionAccountID )( 
            IInterfaceIMAPFolderPermission * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PermissionAccountID )( 
            IInterfaceIMAPFolderPermission * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IInterfaceIMAPFolderPermission * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IInterfaceIMAPFolderPermission * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Permission )( 
            IInterfaceIMAPFolderPermission * This,
            /* [in] */ eACLPermission iType,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Permission )( 
            IInterfaceIMAPFolderPermission * This,
            /* [in] */ eACLPermission iType,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceIMAPFolderPermission * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceIMAPFolderPermission * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Account )( 
            IInterfaceIMAPFolderPermission * This,
            /* [retval][out] */ IInterfaceAccount **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Group )( 
            IInterfaceIMAPFolderPermission * This,
            /* [retval][out] */ IInterfaceGroup **pVal);
        
        END_INTERFACE
    } IInterfaceIMAPFolderPermissionVtbl;

    interface IInterfaceIMAPFolderPermission
    {
        CONST_VTBL struct IInterfaceIMAPFolderPermissionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceIMAPFolderPermission_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceIMAPFolderPermission_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceIMAPFolderPermission_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceIMAPFolderPermission_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceIMAPFolderPermission_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceIMAPFolderPermission_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceIMAPFolderPermission_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceIMAPFolderPermission_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceIMAPFolderPermission_get_ShareFolderID(This,pVal)	\
    ( (This)->lpVtbl -> get_ShareFolderID(This,pVal) ) 

#define IInterfaceIMAPFolderPermission_get_PermissionType(This,pVal)	\
    ( (This)->lpVtbl -> get_PermissionType(This,pVal) ) 

#define IInterfaceIMAPFolderPermission_put_PermissionType(This,newVal)	\
    ( (This)->lpVtbl -> put_PermissionType(This,newVal) ) 

#define IInterfaceIMAPFolderPermission_get_PermissionGroupID(This,pVal)	\
    ( (This)->lpVtbl -> get_PermissionGroupID(This,pVal) ) 

#define IInterfaceIMAPFolderPermission_put_PermissionGroupID(This,newVal)	\
    ( (This)->lpVtbl -> put_PermissionGroupID(This,newVal) ) 

#define IInterfaceIMAPFolderPermission_get_PermissionAccountID(This,pVal)	\
    ( (This)->lpVtbl -> get_PermissionAccountID(This,pVal) ) 

#define IInterfaceIMAPFolderPermission_put_PermissionAccountID(This,newVal)	\
    ( (This)->lpVtbl -> put_PermissionAccountID(This,newVal) ) 

#define IInterfaceIMAPFolderPermission_get_Value(This,pVal)	\
    ( (This)->lpVtbl -> get_Value(This,pVal) ) 

#define IInterfaceIMAPFolderPermission_put_Value(This,newVal)	\
    ( (This)->lpVtbl -> put_Value(This,newVal) ) 

#define IInterfaceIMAPFolderPermission_get_Permission(This,iType,pVal)	\
    ( (This)->lpVtbl -> get_Permission(This,iType,pVal) ) 

#define IInterfaceIMAPFolderPermission_put_Permission(This,iType,pVal)	\
    ( (This)->lpVtbl -> put_Permission(This,iType,pVal) ) 

#define IInterfaceIMAPFolderPermission_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#define IInterfaceIMAPFolderPermission_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IInterfaceIMAPFolderPermission_get_Account(This,pVal)	\
    ( (This)->lpVtbl -> get_Account(This,pVal) ) 

#define IInterfaceIMAPFolderPermission_get_Group(This,pVal)	\
    ( (This)->lpVtbl -> get_Group(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceIMAPFolderPermission_INTERFACE_DEFINED__ */


#ifndef __IInterfaceIMAPFolderPermissions_INTERFACE_DEFINED__
#define __IInterfaceIMAPFolderPermissions_INTERFACE_DEFINED__

/* interface IInterfaceIMAPFolderPermissions */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceIMAPFolderPermissions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CBE3FE9E-3642-4BA1-9BE0-6E766C0DE961")
    IInterfaceIMAPFolderPermissions : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceIMAPFolderPermission **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ long Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceIMAPFolderPermission **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceIMAPFolderPermission **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByName( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ IInterfaceIMAPFolderPermission **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceIMAPFolderPermissionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceIMAPFolderPermissions * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceIMAPFolderPermissions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceIMAPFolderPermissions * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceIMAPFolderPermissions * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceIMAPFolderPermissions * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceIMAPFolderPermissions * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceIMAPFolderPermissions * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceIMAPFolderPermissions * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceIMAPFolderPermission **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceIMAPFolderPermissions * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceIMAPFolderPermissions * This,
            /* [in] */ long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceIMAPFolderPermissions * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceIMAPFolderPermissions * This,
            /* [retval][out] */ IInterfaceIMAPFolderPermission **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceIMAPFolderPermissions * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceIMAPFolderPermission **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceIMAPFolderPermissions * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByName )( 
            IInterfaceIMAPFolderPermissions * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IInterfaceIMAPFolderPermission **pVal);
        
        END_INTERFACE
    } IInterfaceIMAPFolderPermissionsVtbl;

    interface IInterfaceIMAPFolderPermissions
    {
        CONST_VTBL struct IInterfaceIMAPFolderPermissionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceIMAPFolderPermissions_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceIMAPFolderPermissions_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceIMAPFolderPermissions_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceIMAPFolderPermissions_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceIMAPFolderPermissions_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceIMAPFolderPermissions_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceIMAPFolderPermissions_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceIMAPFolderPermissions_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceIMAPFolderPermissions_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceIMAPFolderPermissions_Delete(This,Index)	\
    ( (This)->lpVtbl -> Delete(This,Index) ) 

#define IInterfaceIMAPFolderPermissions_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceIMAPFolderPermissions_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceIMAPFolderPermissions_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceIMAPFolderPermissions_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceIMAPFolderPermissions_get_ItemByName(This,Name,pVal)	\
    ( (This)->lpVtbl -> get_ItemByName(This,Name,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceIMAPFolderPermissions_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDirectories_INTERFACE_DEFINED__
#define __IInterfaceDirectories_INTERFACE_DEFINED__

/* interface IInterfaceDirectories */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDirectories;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("48B534F3-2C4E-47F6-8CB0-339676B0ABF3")
    IInterfaceDirectories : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ProgramDirectory( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ProgramDirectory( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DatabaseDirectory( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DatabaseDirectory( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataDirectory( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DataDirectory( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogDirectory( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LogDirectory( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TempDirectory( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TempDirectory( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EventDirectory( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EventDirectory( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DBScriptDirectory( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDirectoriesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDirectories * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDirectories * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDirectories * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDirectories * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDirectories * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDirectories * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDirectories * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProgramDirectory )( 
            IInterfaceDirectories * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ProgramDirectory )( 
            IInterfaceDirectories * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DatabaseDirectory )( 
            IInterfaceDirectories * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DatabaseDirectory )( 
            IInterfaceDirectories * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DataDirectory )( 
            IInterfaceDirectories * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DataDirectory )( 
            IInterfaceDirectories * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogDirectory )( 
            IInterfaceDirectories * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LogDirectory )( 
            IInterfaceDirectories * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TempDirectory )( 
            IInterfaceDirectories * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TempDirectory )( 
            IInterfaceDirectories * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EventDirectory )( 
            IInterfaceDirectories * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EventDirectory )( 
            IInterfaceDirectories * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DBScriptDirectory )( 
            IInterfaceDirectories * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IInterfaceDirectoriesVtbl;

    interface IInterfaceDirectories
    {
        CONST_VTBL struct IInterfaceDirectoriesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDirectories_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDirectories_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDirectories_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDirectories_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDirectories_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDirectories_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDirectories_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDirectories_get_ProgramDirectory(This,pVal)	\
    ( (This)->lpVtbl -> get_ProgramDirectory(This,pVal) ) 

#define IInterfaceDirectories_put_ProgramDirectory(This,newVal)	\
    ( (This)->lpVtbl -> put_ProgramDirectory(This,newVal) ) 

#define IInterfaceDirectories_get_DatabaseDirectory(This,pVal)	\
    ( (This)->lpVtbl -> get_DatabaseDirectory(This,pVal) ) 

#define IInterfaceDirectories_put_DatabaseDirectory(This,newVal)	\
    ( (This)->lpVtbl -> put_DatabaseDirectory(This,newVal) ) 

#define IInterfaceDirectories_get_DataDirectory(This,pVal)	\
    ( (This)->lpVtbl -> get_DataDirectory(This,pVal) ) 

#define IInterfaceDirectories_put_DataDirectory(This,newVal)	\
    ( (This)->lpVtbl -> put_DataDirectory(This,newVal) ) 

#define IInterfaceDirectories_get_LogDirectory(This,pVal)	\
    ( (This)->lpVtbl -> get_LogDirectory(This,pVal) ) 

#define IInterfaceDirectories_put_LogDirectory(This,newVal)	\
    ( (This)->lpVtbl -> put_LogDirectory(This,newVal) ) 

#define IInterfaceDirectories_get_TempDirectory(This,pVal)	\
    ( (This)->lpVtbl -> get_TempDirectory(This,pVal) ) 

#define IInterfaceDirectories_put_TempDirectory(This,newVal)	\
    ( (This)->lpVtbl -> put_TempDirectory(This,newVal) ) 

#define IInterfaceDirectories_get_EventDirectory(This,pVal)	\
    ( (This)->lpVtbl -> get_EventDirectory(This,pVal) ) 

#define IInterfaceDirectories_put_EventDirectory(This,newVal)	\
    ( (This)->lpVtbl -> put_EventDirectory(This,newVal) ) 

#define IInterfaceDirectories_get_DBScriptDirectory(This,pVal)	\
    ( (This)->lpVtbl -> get_DBScriptDirectory(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDirectories_INTERFACE_DEFINED__ */


#ifndef __IInterfaceLanguages_INTERFACE_DEFINED__
#define __IInterfaceLanguages_INTERFACE_DEFINED__

/* interface IInterfaceLanguages */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceLanguages;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("94720D8A-BC4D-493D-8BDC-8FB28BF31BA5")
    IInterfaceLanguages : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceLanguage **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByName( 
            /* [in] */ BSTR ItemName,
            /* [retval][out] */ IInterfaceLanguage **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceLanguagesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceLanguages * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceLanguages * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceLanguages * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceLanguages * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceLanguages * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceLanguages * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceLanguages * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceLanguages * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceLanguage **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceLanguages * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByName )( 
            IInterfaceLanguages * This,
            /* [in] */ BSTR ItemName,
            /* [retval][out] */ IInterfaceLanguage **pVal);
        
        END_INTERFACE
    } IInterfaceLanguagesVtbl;

    interface IInterfaceLanguages
    {
        CONST_VTBL struct IInterfaceLanguagesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceLanguages_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceLanguages_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceLanguages_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceLanguages_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceLanguages_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceLanguages_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceLanguages_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceLanguages_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceLanguages_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceLanguages_get_ItemByName(This,ItemName,pVal)	\
    ( (This)->lpVtbl -> get_ItemByName(This,ItemName,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceLanguages_INTERFACE_DEFINED__ */


#ifndef __IInterfaceLinks_INTERFACE_DEFINED__
#define __IInterfaceLinks_INTERFACE_DEFINED__

/* interface IInterfaceLinks */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceLinks;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E252D063-7E86-4FCE-B702-A5E89E0DFB48")
    IInterfaceLinks : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Domain( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDomain **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Account( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceAccount **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Alias( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceAlias **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DistributionList( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDistributionList **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceLinksVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceLinks * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceLinks * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceLinks * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceLinks * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceLinks * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceLinks * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceLinks * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Domain )( 
            IInterfaceLinks * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDomain **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Account )( 
            IInterfaceLinks * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceAccount **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Alias )( 
            IInterfaceLinks * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceAlias **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DistributionList )( 
            IInterfaceLinks * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceDistributionList **pVal);
        
        END_INTERFACE
    } IInterfaceLinksVtbl;

    interface IInterfaceLinks
    {
        CONST_VTBL struct IInterfaceLinksVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceLinks_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceLinks_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceLinks_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceLinks_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceLinks_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceLinks_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceLinks_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceLinks_get_Domain(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_Domain(This,DBID,pVal) ) 

#define IInterfaceLinks_get_Account(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_Account(This,DBID,pVal) ) 

#define IInterfaceLinks_get_Alias(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_Alias(This,DBID,pVal) ) 

#define IInterfaceLinks_get_DistributionList(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_DistributionList(This,DBID,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceLinks_INTERFACE_DEFINED__ */


#ifndef __IInterfaceIncomingRelay_INTERFACE_DEFINED__
#define __IInterfaceIncomingRelay_INTERFACE_DEFINED__

/* interface IInterfaceIncomingRelay */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceIncomingRelay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("088D748B-7CCE-4B8D-A103-D99DA83775AB")
    IInterfaceIncomingRelay : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LowerIP( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LowerIP( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UpperIP( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UpperIP( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceIncomingRelayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceIncomingRelay * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceIncomingRelay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceIncomingRelay * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceIncomingRelay * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceIncomingRelay * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceIncomingRelay * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceIncomingRelay * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IInterfaceIncomingRelay * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LowerIP )( 
            IInterfaceIncomingRelay * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LowerIP )( 
            IInterfaceIncomingRelay * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UpperIP )( 
            IInterfaceIncomingRelay * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UpperIP )( 
            IInterfaceIncomingRelay * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceIncomingRelay * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IInterfaceIncomingRelay * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceIncomingRelay * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            IInterfaceIncomingRelay * This);
        
        END_INTERFACE
    } IInterfaceIncomingRelayVtbl;

    interface IInterfaceIncomingRelay
    {
        CONST_VTBL struct IInterfaceIncomingRelayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceIncomingRelay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceIncomingRelay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceIncomingRelay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceIncomingRelay_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceIncomingRelay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceIncomingRelay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceIncomingRelay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceIncomingRelay_get_ID(This,pVal)	\
    ( (This)->lpVtbl -> get_ID(This,pVal) ) 

#define IInterfaceIncomingRelay_get_LowerIP(This,pVal)	\
    ( (This)->lpVtbl -> get_LowerIP(This,pVal) ) 

#define IInterfaceIncomingRelay_put_LowerIP(This,pVal)	\
    ( (This)->lpVtbl -> put_LowerIP(This,pVal) ) 

#define IInterfaceIncomingRelay_get_UpperIP(This,pVal)	\
    ( (This)->lpVtbl -> get_UpperIP(This,pVal) ) 

#define IInterfaceIncomingRelay_put_UpperIP(This,pVal)	\
    ( (This)->lpVtbl -> put_UpperIP(This,pVal) ) 

#define IInterfaceIncomingRelay_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceIncomingRelay_put_Name(This,newVal)	\
    ( (This)->lpVtbl -> put_Name(This,newVal) ) 

#define IInterfaceIncomingRelay_Delete(This)	\
    ( (This)->lpVtbl -> Delete(This) ) 

#define IInterfaceIncomingRelay_Save(This)	\
    ( (This)->lpVtbl -> Save(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceIncomingRelay_INTERFACE_DEFINED__ */


#ifndef __IInterfaceIncomingRelays_INTERFACE_DEFINED__
#define __IInterfaceIncomingRelays_INTERFACE_DEFINED__

/* interface IInterfaceIncomingRelays */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceIncomingRelays;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("49D48933-3219-4D7E-84D5-B26FE5F0E165")
    IInterfaceIncomingRelays : public IDispatch
    {
    public:
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceIncomingRelay **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByDBID( 
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceIncomingRelay **pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ long Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteByDBID( 
            /* [in] */ long DBID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Refresh( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [retval][out] */ IInterfaceIncomingRelay **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemByName( 
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceIncomingRelay **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceIncomingRelaysVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceIncomingRelays * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceIncomingRelays * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceIncomingRelays * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceIncomingRelays * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceIncomingRelays * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceIncomingRelays * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceIncomingRelays * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceIncomingRelays * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceIncomingRelay **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByDBID )( 
            IInterfaceIncomingRelays * This,
            /* [in] */ long DBID,
            /* [retval][out] */ IInterfaceIncomingRelay **pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IInterfaceIncomingRelays * This,
            /* [in] */ long Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteByDBID )( 
            IInterfaceIncomingRelays * This,
            /* [in] */ long DBID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IInterfaceIncomingRelays * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IInterfaceIncomingRelays * This,
            /* [retval][out] */ IInterfaceIncomingRelay **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceIncomingRelays * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemByName )( 
            IInterfaceIncomingRelays * This,
            /* [in] */ BSTR sName,
            /* [retval][out] */ IInterfaceIncomingRelay **pVal);
        
        END_INTERFACE
    } IInterfaceIncomingRelaysVtbl;

    interface IInterfaceIncomingRelays
    {
        CONST_VTBL struct IInterfaceIncomingRelaysVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceIncomingRelays_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceIncomingRelays_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceIncomingRelays_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceIncomingRelays_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceIncomingRelays_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceIncomingRelays_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceIncomingRelays_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceIncomingRelays_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#define IInterfaceIncomingRelays_get_ItemByDBID(This,DBID,pVal)	\
    ( (This)->lpVtbl -> get_ItemByDBID(This,DBID,pVal) ) 

#define IInterfaceIncomingRelays_Delete(This,Index)	\
    ( (This)->lpVtbl -> Delete(This,Index) ) 

#define IInterfaceIncomingRelays_DeleteByDBID(This,DBID)	\
    ( (This)->lpVtbl -> DeleteByDBID(This,DBID) ) 

#define IInterfaceIncomingRelays_Refresh(This)	\
    ( (This)->lpVtbl -> Refresh(This) ) 

#define IInterfaceIncomingRelays_Add(This,pVal)	\
    ( (This)->lpVtbl -> Add(This,pVal) ) 

#define IInterfaceIncomingRelays_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceIncomingRelays_get_ItemByName(This,sName,pVal)	\
    ( (This)->lpVtbl -> get_ItemByName(This,sName,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceIncomingRelays_INTERFACE_DEFINED__ */


#ifndef __IInterfaceMessageIndexing_INTERFACE_DEFINED__
#define __IInterfaceMessageIndexing_INTERFACE_DEFINED__

/* interface IInterfaceMessageIndexing */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceMessageIndexing;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C58B6AD-48CC-4775-B283-53C77F717EB9")
    IInterfaceMessageIndexing : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TotalMessageCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TotalIndexedCount( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Index( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceMessageIndexingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceMessageIndexing * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceMessageIndexing * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceMessageIndexing * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceMessageIndexing * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceMessageIndexing * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceMessageIndexing * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceMessageIndexing * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TotalMessageCount )( 
            IInterfaceMessageIndexing * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TotalIndexedCount )( 
            IInterfaceMessageIndexing * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IInterfaceMessageIndexing * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IInterfaceMessageIndexing * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IInterfaceMessageIndexing * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Index )( 
            IInterfaceMessageIndexing * This);
        
        END_INTERFACE
    } IInterfaceMessageIndexingVtbl;

    interface IInterfaceMessageIndexing
    {
        CONST_VTBL struct IInterfaceMessageIndexingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceMessageIndexing_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceMessageIndexing_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceMessageIndexing_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceMessageIndexing_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceMessageIndexing_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceMessageIndexing_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceMessageIndexing_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceMessageIndexing_get_TotalMessageCount(This,pVal)	\
    ( (This)->lpVtbl -> get_TotalMessageCount(This,pVal) ) 

#define IInterfaceMessageIndexing_get_TotalIndexedCount(This,pVal)	\
    ( (This)->lpVtbl -> get_TotalIndexedCount(This,pVal) ) 

#define IInterfaceMessageIndexing_get_Enabled(This,pVal)	\
    ( (This)->lpVtbl -> get_Enabled(This,pVal) ) 

#define IInterfaceMessageIndexing_put_Enabled(This,newVal)	\
    ( (This)->lpVtbl -> put_Enabled(This,newVal) ) 

#define IInterfaceMessageIndexing_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IInterfaceMessageIndexing_Index(This)	\
    ( (This)->lpVtbl -> Index(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceMessageIndexing_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDiagnostics_INTERFACE_DEFINED__
#define __IInterfaceDiagnostics_INTERFACE_DEFINED__

/* interface IInterfaceDiagnostics */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDiagnostics;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FB8812B0-524A-4922-9E29-A7E9A9E9151D")
    IInterfaceDiagnostics : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PerformTests( 
            /* [retval][out] */ IInterfaceDiagnosticResults **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LocalDomainName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LocalDomainName( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TestDomainName( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TestDomainName( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDiagnosticsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDiagnostics * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDiagnostics * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDiagnostics * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDiagnostics * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDiagnostics * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDiagnostics * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDiagnostics * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PerformTests )( 
            IInterfaceDiagnostics * This,
            /* [retval][out] */ IInterfaceDiagnosticResults **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LocalDomainName )( 
            IInterfaceDiagnostics * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LocalDomainName )( 
            IInterfaceDiagnostics * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TestDomainName )( 
            IInterfaceDiagnostics * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TestDomainName )( 
            IInterfaceDiagnostics * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IInterfaceDiagnosticsVtbl;

    interface IInterfaceDiagnostics
    {
        CONST_VTBL struct IInterfaceDiagnosticsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDiagnostics_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDiagnostics_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDiagnostics_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDiagnostics_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDiagnostics_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDiagnostics_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDiagnostics_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDiagnostics_PerformTests(This,pVal)	\
    ( (This)->lpVtbl -> PerformTests(This,pVal) ) 

#define IInterfaceDiagnostics_get_LocalDomainName(This,pVal)	\
    ( (This)->lpVtbl -> get_LocalDomainName(This,pVal) ) 

#define IInterfaceDiagnostics_put_LocalDomainName(This,newVal)	\
    ( (This)->lpVtbl -> put_LocalDomainName(This,newVal) ) 

#define IInterfaceDiagnostics_get_TestDomainName(This,pVal)	\
    ( (This)->lpVtbl -> get_TestDomainName(This,pVal) ) 

#define IInterfaceDiagnostics_put_TestDomainName(This,newVal)	\
    ( (This)->lpVtbl -> put_TestDomainName(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDiagnostics_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDiagnosticResults_INTERFACE_DEFINED__
#define __IInterfaceDiagnosticResults_INTERFACE_DEFINED__

/* interface IInterfaceDiagnosticResults */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDiagnosticResults;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("27EDFA15-CD0B-40C9-86D0-1BB11B3A1310")
    IInterfaceDiagnosticResults : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][defaultbind][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceDiagnosticResult **pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDiagnosticResultsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDiagnosticResults * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDiagnosticResults * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDiagnosticResults * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDiagnosticResults * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDiagnosticResults * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDiagnosticResults * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDiagnosticResults * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IInterfaceDiagnosticResults * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][defaultbind][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IInterfaceDiagnosticResults * This,
            /* [in] */ long Index,
            /* [retval][out] */ IInterfaceDiagnosticResult **pVal);
        
        END_INTERFACE
    } IInterfaceDiagnosticResultsVtbl;

    interface IInterfaceDiagnosticResults
    {
        CONST_VTBL struct IInterfaceDiagnosticResultsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDiagnosticResults_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDiagnosticResults_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDiagnosticResults_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDiagnosticResults_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDiagnosticResults_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDiagnosticResults_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDiagnosticResults_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDiagnosticResults_get_Count(This,pVal)	\
    ( (This)->lpVtbl -> get_Count(This,pVal) ) 

#define IInterfaceDiagnosticResults_get_Item(This,Index,pVal)	\
    ( (This)->lpVtbl -> get_Item(This,Index,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDiagnosticResults_INTERFACE_DEFINED__ */


#ifndef __IInterfaceDiagnosticResult_INTERFACE_DEFINED__
#define __IInterfaceDiagnosticResult_INTERFACE_DEFINED__

/* interface IInterfaceDiagnosticResult */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInterfaceDiagnosticResult;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7E97DEEC-29B3-4ADA-8524-EA8CEEE38918")
    IInterfaceDiagnosticResult : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExecutionDetails( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Result( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IInterfaceDiagnosticResultVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInterfaceDiagnosticResult * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInterfaceDiagnosticResult * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInterfaceDiagnosticResult * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInterfaceDiagnosticResult * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInterfaceDiagnosticResult * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInterfaceDiagnosticResult * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInterfaceDiagnosticResult * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IInterfaceDiagnosticResult * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IInterfaceDiagnosticResult * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExecutionDetails )( 
            IInterfaceDiagnosticResult * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Result )( 
            IInterfaceDiagnosticResult * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        END_INTERFACE
    } IInterfaceDiagnosticResultVtbl;

    interface IInterfaceDiagnosticResult
    {
        CONST_VTBL struct IInterfaceDiagnosticResultVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInterfaceDiagnosticResult_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInterfaceDiagnosticResult_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInterfaceDiagnosticResult_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInterfaceDiagnosticResult_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInterfaceDiagnosticResult_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInterfaceDiagnosticResult_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInterfaceDiagnosticResult_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInterfaceDiagnosticResult_get_Name(This,pVal)	\
    ( (This)->lpVtbl -> get_Name(This,pVal) ) 

#define IInterfaceDiagnosticResult_get_Description(This,pVal)	\
    ( (This)->lpVtbl -> get_Description(This,pVal) ) 

#define IInterfaceDiagnosticResult_get_ExecutionDetails(This,pVal)	\
    ( (This)->lpVtbl -> get_ExecutionDetails(This,pVal) ) 

#define IInterfaceDiagnosticResult_get_Result(This,pVal)	\
    ( (This)->lpVtbl -> get_Result(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInterfaceDiagnosticResult_INTERFACE_DEFINED__ */



#ifndef __hMailServer_LIBRARY_DEFINED__
#define __hMailServer_LIBRARY_DEFINED__

/* library hMailServer */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_hMailServer;

EXTERN_C const CLSID CLSID_DiagnosticResults;

#ifdef __cplusplus

class DECLSPEC_UUID("3AC49BB3-3F3C-4D82-AC0F-28464C408EA9")
DiagnosticResults;
#endif

EXTERN_C const CLSID CLSID_DiagnosticResult;

#ifdef __cplusplus

class DECLSPEC_UUID("430C3328-6348-4A86-8E12-74B5B5EFF48D")
DiagnosticResult;
#endif

EXTERN_C const CLSID CLSID_Diagnostics;

#ifdef __cplusplus

class DECLSPEC_UUID("EB576B35-8F97-47AB-A0D1-80A3D514610B")
Diagnostics;
#endif

EXTERN_C const CLSID CLSID_Status;

#ifdef __cplusplus

class DECLSPEC_UUID("ADD8B04F-F7A0-4C73-8B0B-E53B3077F052")
Status;
#endif

EXTERN_C const CLSID CLSID_Settings;

#ifdef __cplusplus

class DECLSPEC_UUID("FDF084A7-82DE-4EBE-8455-E506ACE01D63")
Settings;
#endif

EXTERN_C const CLSID CLSID_Domain;

#ifdef __cplusplus

class DECLSPEC_UUID("C535E4AF-9DB3-41FC-B434-FFCDAE0EFBD5")
Domain;
#endif

EXTERN_C const CLSID CLSID_Accounts;

#ifdef __cplusplus

class DECLSPEC_UUID("403A75B8-499A-44C1-93D3-6A8A460AA88D")
Accounts;
#endif

EXTERN_C const CLSID CLSID_Account;

#ifdef __cplusplus

class DECLSPEC_UUID("369BE902-9F27-4722-A29F-3059E4D7021D")
Account;
#endif

EXTERN_C const CLSID CLSID_Database;

#ifdef __cplusplus

class DECLSPEC_UUID("2F5BEF2E-C713-4826-88AE-A5FD9921907B")
Database;
#endif

EXTERN_C const CLSID CLSID_Message;

#ifdef __cplusplus

class DECLSPEC_UUID("61B2C7D7-3814-441F-9574-EE2CC9829447")
Message;
#endif

EXTERN_C const CLSID CLSID_Messages;

#ifdef __cplusplus

class DECLSPEC_UUID("C04047AD-45A4-48EA-907E-2C270C95409C")
Messages;
#endif

EXTERN_C const CLSID CLSID_Aliases;

#ifdef __cplusplus

class DECLSPEC_UUID("1FE5E5F1-870A-4139-9EC1-DFFA3A9A58C8")
Aliases;
#endif

EXTERN_C const CLSID CLSID_Utilities;

#ifdef __cplusplus

class DECLSPEC_UUID("E116DCB7-7FEC-4540-BEA1-FA1B19D05B5F")
Utilities;
#endif

EXTERN_C const CLSID CLSID_Alias;

#ifdef __cplusplus

class DECLSPEC_UUID("335CE9E1-32C5-4CB0-8BF6-CB925196E4D6")
Alias;
#endif

EXTERN_C const CLSID CLSID_Attachment;

#ifdef __cplusplus

class DECLSPEC_UUID("B65A156A-54D1-4803-80CE-273F44AE935F")
Attachment;
#endif

EXTERN_C const CLSID CLSID_Attachments;

#ifdef __cplusplus

class DECLSPEC_UUID("63FF738A-982B-41E6-87C7-BA4AA9622B30")
Attachments;
#endif

EXTERN_C const CLSID CLSID_Logging;

#ifdef __cplusplus

class DECLSPEC_UUID("E3E22438-871F-49CF-A47E-4D3A144BD002")
Logging;
#endif

EXTERN_C const CLSID CLSID_DistributionLists;

#ifdef __cplusplus

class DECLSPEC_UUID("C3DD0A4A-0551-442F-859A-76AAB92A6CF1")
DistributionLists;
#endif

EXTERN_C const CLSID CLSID_DistributionList;

#ifdef __cplusplus

class DECLSPEC_UUID("990D27ED-86CE-4DCB-B1C1-1E130C07F918")
DistributionList;
#endif

EXTERN_C const CLSID CLSID_DistributionListRecipients;

#ifdef __cplusplus

class DECLSPEC_UUID("AB59F3C1-4904-4F1D-883A-4BFC699A7D0B")
DistributionListRecipients;
#endif

EXTERN_C const CLSID CLSID_DistributionListRecipient;

#ifdef __cplusplus

class DECLSPEC_UUID("0886D5D8-4C1C-46F1-BC7B-EEDC9FE9DFFA")
DistributionListRecipient;
#endif

EXTERN_C const CLSID CLSID_SecurityRange;

#ifdef __cplusplus

class DECLSPEC_UUID("B149383D-151C-4585-99F8-71876D0F14C4")
SecurityRange;
#endif

EXTERN_C const CLSID CLSID_SecurityRanges;

#ifdef __cplusplus

class DECLSPEC_UUID("60A752A2-1197-4841-ADD4-CE922873E794")
SecurityRanges;
#endif

EXTERN_C const CLSID CLSID_AntiVirus;

#ifdef __cplusplus

class DECLSPEC_UUID("82D6DBF9-DDDB-4C4A-A52A-92B6ED16D8EA")
AntiVirus;
#endif

EXTERN_C const CLSID CLSID_Route;

#ifdef __cplusplus

class DECLSPEC_UUID("3FF9BB08-7924-4418-BADA-7D959467D51B")
Route;
#endif

EXTERN_C const CLSID CLSID_DNSBlackLists;

#ifdef __cplusplus

class DECLSPEC_UUID("39ECFFB4-B9EE-46C2-A84B-32D679FB3C82")
DNSBlackLists;
#endif

EXTERN_C const CLSID CLSID_DNSBlackList;

#ifdef __cplusplus

class DECLSPEC_UUID("E5907F7D-F13E-4D8A-A7DE-A29717C75A8F")
DNSBlackList;
#endif

EXTERN_C const CLSID CLSID_Application;

#ifdef __cplusplus

class DECLSPEC_UUID("D6567EF8-0A6C-48E7-9288-A2463123C2F3")
Application;
#endif

EXTERN_C const CLSID CLSID_Domains;

#ifdef __cplusplus

class DECLSPEC_UUID("82AFD03C-58A4-4F04-8277-6B2812780E45")
Domains;
#endif

EXTERN_C const CLSID CLSID_Routes;

#ifdef __cplusplus

class DECLSPEC_UUID("7D174A9D-D44C-4627-BE78-E5DDC513C31F")
Routes;
#endif

EXTERN_C const CLSID CLSID_RouteAddress;

#ifdef __cplusplus

class DECLSPEC_UUID("4CC5C4F5-7303-4C69-96D3-EC73ECF6F255")
RouteAddress;
#endif

EXTERN_C const CLSID CLSID_RouteAddresses;

#ifdef __cplusplus

class DECLSPEC_UUID("2E66E5DC-DA9F-4490-A46F-E2D24C6CD151")
RouteAddresses;
#endif

EXTERN_C const CLSID CLSID_Result;

#ifdef __cplusplus

class DECLSPEC_UUID("F493160B-C38D-407D-9BF5-A7B23225B8E0")
Result;
#endif

EXTERN_C const CLSID CLSID_Client;

#ifdef __cplusplus

class DECLSPEC_UUID("B5EFB246-4F4B-4B11-A9D1-3C14AB528871")
Client;
#endif

EXTERN_C const CLSID CLSID_FetchAccount;

#ifdef __cplusplus

class DECLSPEC_UUID("6F5E2977-2F51-40B0-847B-DD44C9ACC5A5")
FetchAccount;
#endif

EXTERN_C const CLSID CLSID_FetchAccounts;

#ifdef __cplusplus

class DECLSPEC_UUID("F17C3A00-A7A0-4519-AEDD-DCC3B8DE6A3D")
FetchAccounts;
#endif

EXTERN_C const CLSID CLSID_Scripting;

#ifdef __cplusplus

class DECLSPEC_UUID("68A73A47-5B56-43A3-BC11-CFC436F3BA9E")
Scripting;
#endif

EXTERN_C const CLSID CLSID_DomainAliases;

#ifdef __cplusplus

class DECLSPEC_UUID("DC25B3AD-0360-49CA-AD4B-06FA42B9DF04")
DomainAliases;
#endif

EXTERN_C const CLSID CLSID_DomainAlias;

#ifdef __cplusplus

class DECLSPEC_UUID("D0061C74-5588-4796-B564-FE5DE85495DC")
DomainAlias;
#endif

EXTERN_C const CLSID CLSID_Rules;

#ifdef __cplusplus

class DECLSPEC_UUID("624F494B-347A-4285-9506-C54154D50B2A")
Rules;
#endif

EXTERN_C const CLSID CLSID_Rule;

#ifdef __cplusplus

class DECLSPEC_UUID("D5D7927A-7D05-40F3-91DD-968FC14316C7")
Rule;
#endif

EXTERN_C const CLSID CLSID_RuleCriteria;

#ifdef __cplusplus

class DECLSPEC_UUID("3F0EB97B-C698-498C-965A-06ED393AC50C")
RuleCriteria;
#endif

EXTERN_C const CLSID CLSID_RuleCriterias;

#ifdef __cplusplus

class DECLSPEC_UUID("E90022A1-61CF-4152-B9D9-27D04D0BA362")
RuleCriterias;
#endif

EXTERN_C const CLSID CLSID_RuleAction;

#ifdef __cplusplus

class DECLSPEC_UUID("35548CC2-14AE-4795-8A19-C78FDE208504")
RuleAction;
#endif

EXTERN_C const CLSID CLSID_RuleActions;

#ifdef __cplusplus

class DECLSPEC_UUID("32A21952-5421-4A6C-835A-41050D0493C1")
RuleActions;
#endif

EXTERN_C const CLSID CLSID_Recipients;

#ifdef __cplusplus

class DECLSPEC_UUID("B5B9C42D-64F1-443F-AA0D-FABB2DD9317B")
Recipients;
#endif

EXTERN_C const CLSID CLSID_Recipient;

#ifdef __cplusplus

class DECLSPEC_UUID("45B82F51-8445-4F3A-BC9E-137FC04BFE2A")
Recipient;
#endif

EXTERN_C const CLSID CLSID_Cache;

#ifdef __cplusplus

class DECLSPEC_UUID("B16F527C-116F-4F6B-B669-9A00326E255B")
Cache;
#endif

EXTERN_C const CLSID CLSID_BackupManager;

#ifdef __cplusplus

class DECLSPEC_UUID("1BBE5234-D331-41DF-85D7-CAF0B00B3BF7")
BackupManager;
#endif

EXTERN_C const CLSID CLSID_BackupSettings;

#ifdef __cplusplus

class DECLSPEC_UUID("E0213ECF-BAEC-4E20-9813-0F75A97D0B16")
BackupSettings;
#endif

EXTERN_C const CLSID CLSID_Backup;

#ifdef __cplusplus

class DECLSPEC_UUID("B088FED1-A784-4CDB-ADDF-E7332CB7F72F")
Backup;
#endif

EXTERN_C const CLSID CLSID_GlobalObjects;

#ifdef __cplusplus

class DECLSPEC_UUID("D8CC854E-F6F6-402C-ADF7-73F4569B9F8B")
GlobalObjects;
#endif

EXTERN_C const CLSID CLSID_DeliveryQueue;

#ifdef __cplusplus

class DECLSPEC_UUID("27473BB7-4272-4693-ACA6-FD9D4C9C3FC5")
DeliveryQueue;
#endif

EXTERN_C const CLSID CLSID_Language;

#ifdef __cplusplus

class DECLSPEC_UUID("1C70E18B-C63D-458C-B080-64E4F94C4E83")
Language;
#endif

EXTERN_C const CLSID CLSID_IMAPFolder;

#ifdef __cplusplus

class DECLSPEC_UUID("9FCA085E-E475-4DEE-9D45-5519818DD6E0")
IMAPFolder;
#endif

EXTERN_C const CLSID CLSID_IMAPFolders;

#ifdef __cplusplus

class DECLSPEC_UUID("A0AAF31A-570A-4B78-BDAB-4C33E34BE85F")
IMAPFolders;
#endif

EXTERN_C const CLSID CLSID_EventLog;

#ifdef __cplusplus

class DECLSPEC_UUID("D8D10BF8-87FD-4D1B-B937-23A420CF064E")
EventLog;
#endif

EXTERN_C const CLSID CLSID_SURBLServers;

#ifdef __cplusplus

class DECLSPEC_UUID("FCD94E5F-F05F-400B-8345-AFC7FDD6626E")
SURBLServers;
#endif

EXTERN_C const CLSID CLSID_SURBLServer;

#ifdef __cplusplus

class DECLSPEC_UUID("D875AEC4-7AA0-4C93-9F8F-141324C80D17")
SURBLServer;
#endif

EXTERN_C const CLSID CLSID_AntiSpam;

#ifdef __cplusplus

class DECLSPEC_UUID("A0B91A99-BCE8-4939-94EC-0881E25A1E5B")
AntiSpam;
#endif

EXTERN_C const CLSID CLSID_BlockedAttachment;

#ifdef __cplusplus

class DECLSPEC_UUID("773BCF69-C1C2-48CD-A8F8-E89A1F74E4B3")
BlockedAttachment;
#endif

EXTERN_C const CLSID CLSID_BlockedAttachments;

#ifdef __cplusplus

class DECLSPEC_UUID("1E93E771-45C1-4CAD-9BF6-5D79723C9CBE")
BlockedAttachments;
#endif

EXTERN_C const CLSID CLSID_ServerMessages;

#ifdef __cplusplus

class DECLSPEC_UUID("379F1428-A4C9-4D43-9745-AEABF8950755")
ServerMessages;
#endif

EXTERN_C const CLSID CLSID_ServerMessage;

#ifdef __cplusplus

class DECLSPEC_UUID("561076C6-9174-43D3-B889-CFCC42E3AE5E")
ServerMessage;
#endif

EXTERN_C const CLSID CLSID_TCPIPPort;

#ifdef __cplusplus

class DECLSPEC_UUID("556DF811-3E02-4106-BCA6-C75996825E9A")
TCPIPPort;
#endif

EXTERN_C const CLSID CLSID_TCPIPPorts;

#ifdef __cplusplus

class DECLSPEC_UUID("225808B4-6F03-4750-843F-3150EB1C357F")
TCPIPPorts;
#endif

EXTERN_C const CLSID CLSID_GreyListingWhiteAddress;

#ifdef __cplusplus

class DECLSPEC_UUID("771EDD01-0E62-4071-AE72-88E439EC0880")
GreyListingWhiteAddress;
#endif

EXTERN_C const CLSID CLSID_GreyListingWhiteAddresses;

#ifdef __cplusplus

class DECLSPEC_UUID("F8BB11B8-5DD1-438E-AF29-6E088AA0BD06")
GreyListingWhiteAddresses;
#endif

EXTERN_C const CLSID CLSID_WhiteListAddresses;

#ifdef __cplusplus

class DECLSPEC_UUID("FACFAF38-7BEE-48B4-A47E-D623ACCAE9AB")
WhiteListAddresses;
#endif

EXTERN_C const CLSID CLSID_WhiteListAddress;

#ifdef __cplusplus

class DECLSPEC_UUID("0B18E4F3-4423-403E-B275-1D95CBD353CE")
WhiteListAddress;
#endif

EXTERN_C const CLSID CLSID_MessageHeader;

#ifdef __cplusplus

class DECLSPEC_UUID("983EE030-380D-4E39-850D-AA543F3C1CB9")
MessageHeader;
#endif

EXTERN_C const CLSID CLSID_MessageHeaders;

#ifdef __cplusplus

class DECLSPEC_UUID("AE360CD2-BB40-4B39-83A6-84516C865365")
MessageHeaders;
#endif

EXTERN_C const CLSID CLSID_SSLCertificate;

#ifdef __cplusplus

class DECLSPEC_UUID("11A68C45-EC73-496A-A300-2EB8820824EF")
SSLCertificate;
#endif

EXTERN_C const CLSID CLSID_SSLCertificates;

#ifdef __cplusplus

class DECLSPEC_UUID("BE7AF6BB-2ECA-4313-BE00-16A72D82AE49")
SSLCertificates;
#endif

EXTERN_C const CLSID CLSID_Groups;

#ifdef __cplusplus

class DECLSPEC_UUID("7573CF89-DF41-4079-91B1-894A0DF3E783")
Groups;
#endif

EXTERN_C const CLSID CLSID_Group;

#ifdef __cplusplus

class DECLSPEC_UUID("8F91E8CB-7DE5-494F-92BD-A245D8CC7E15")
Group;
#endif

EXTERN_C const CLSID CLSID_GroupMembers;

#ifdef __cplusplus

class DECLSPEC_UUID("19BD0117-D6EF-49B3-AAC9-9CE70266AEFF")
GroupMembers;
#endif

EXTERN_C const CLSID CLSID_GroupMember;

#ifdef __cplusplus

class DECLSPEC_UUID("2AF5F36A-6475-43D3-A037-D31C1FEA7BA8")
GroupMember;
#endif

EXTERN_C const CLSID CLSID_IMAPFolderPermission;

#ifdef __cplusplus

class DECLSPEC_UUID("D5800098-1033-4D83-9E06-94F6E1B557F9")
IMAPFolderPermission;
#endif

EXTERN_C const CLSID CLSID_IMAPFolderPermissions;

#ifdef __cplusplus

class DECLSPEC_UUID("A6B391A4-72C8-44AA-9480-9FB3BD593B46")
IMAPFolderPermissions;
#endif

EXTERN_C const CLSID CLSID_Directories;

#ifdef __cplusplus

class DECLSPEC_UUID("1969A4DF-B1B0-4A71-8196-5FD392CA3D8A")
Directories;
#endif

EXTERN_C const CLSID CLSID_Languages;

#ifdef __cplusplus

class DECLSPEC_UUID("BE1070A2-9265-495E-B134-27FAA93916CE")
Languages;
#endif

EXTERN_C const CLSID CLSID_Links;

#ifdef __cplusplus

class DECLSPEC_UUID("88A65C5B-916D-4A79-948A-B0DEE0454804")
Links;
#endif

EXTERN_C const CLSID CLSID_IncomingRelay;

#ifdef __cplusplus

class DECLSPEC_UUID("CB3F5F58-436C-4358-8E1C-1BE1F6D822BC")
IncomingRelay;
#endif

EXTERN_C const CLSID CLSID_IncomingRelays;

#ifdef __cplusplus

class DECLSPEC_UUID("3E75EE53-EAA6-40A5-B2CE-9CB8D7EE9278")
IncomingRelays;
#endif

EXTERN_C const CLSID CLSID_MessageIndexing;

#ifdef __cplusplus

class DECLSPEC_UUID("5F414F73-8E29-4E51-86F2-13C12EF9227A")
MessageIndexing;
#endif
#endif /* __hMailServer_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


