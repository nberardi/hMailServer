hm_drop_table_objects 'hm_accounts'

alter table hm_accounts alter column accountaddress nvarchar(255) not null

alter table hm_accounts alter column accountpassword nvarchar(255) not null

alter table hm_accounts alter column accountforwardaddress nvarchar(255) not null

alter table hm_accounts alter column accountforwardaddress nvarchar(255) not null

ALTER TABLE hm_accounts ADD CONSTRAINT hm_accounts_pk PRIMARY KEY NONCLUSTERED (accountid) 

ALTER TABLE hm_accounts ADD CONSTRAINT u_accountaddress UNIQUE NONCLUSTERED (accountaddress) 

CREATE CLUSTERED INDEX idx_hm_accounts ON hm_accounts (accountaddress) 

hm_drop_table_objects 'hm_aliases'

alter table hm_aliases alter column aliasname nvarchar(255) not null

alter table hm_aliases alter column aliasvalue nvarchar(255) not null

ALTER TABLE hm_aliases ADD CONSTRAINT hm_aliases_pk PRIMARY KEY NONCLUSTERED (aliasid) 

ALTER TABLE hm_aliases ADD CONSTRAINT u_aliasname UNIQUE NONCLUSTERED (aliasname) 

CREATE CLUSTERED INDEX idx_hm_aliases ON hm_aliases (aliasdomainid, aliasname) 

hm_drop_table_objects 'hm_domains'

alter table hm_domains alter column domainname nvarchar(80) not null

alter table hm_domains alter column domainpostmaster nvarchar(80) not null

alter table hm_domains alter column domainplusaddressingchar nvarchar(1) not null

alter table hm_domains alter column domainplusaddressingchar nvarchar(1) not null

ALTER TABLE hm_domains ADD CONSTRAINT hm_domains_pk PRIMARY KEY NONCLUSTERED (domainid) 

ALTER TABLE hm_domains ADD CONSTRAINT u_domainname UNIQUE NONCLUSTERED (domainname) 

CREATE CLUSTERED INDEX idx_hm_domains ON hm_domains (domainname)  

alter table hm_domain_aliases alter column daalias nvarchar(255) not null

alter table hm_messages alter column messagefilename nvarchar(255) not null

alter table hm_messages alter column messagefrom nvarchar(255) not null

hm_drop_table_objects 'hm_settings'

alter table hm_settings alter column settingname nvarchar(30) not null

ALTER TABLE hm_settings ADD CONSTRAINT hm_settings_pk PRIMARY KEY NONCLUSTERED (settingid) 

ALTER TABLE hm_settings ADD CONSTRAINT u_settingname UNIQUE NONCLUSTERED (settingname) 

hm_drop_table_objects 'hm_distributionlists'

alter table hm_distributionlists alter column distributionlistaddress nvarchar(255) not null

alter table hm_distributionlists alter column distributionlistrequireaddress nvarchar(255) not null

ALTER TABLE hm_distributionlists ADD CONSTRAINT hm_distributionlists_pk PRIMARY KEY NONCLUSTERED (distributionlistid) 

ALTER TABLE hm_distributionlists ADD CONSTRAINT u_distributionlistaddress UNIQUE NONCLUSTERED (distributionlistaddress) 

ALTER TABLE hm_distributionlistsrecipients alter column distributionlistrecipientaddress nvarchar(255) NOT NULL

CREATE CLUSTERED INDEX idx_hm_distributionlists_distributionlistdomainid ON hm_distributionlists (distributionlistdomainid) 

alter table hm_messagerecipients alter column recipientaddress nvarchar(255) not null

alter table hm_messagerecipients alter column recipientoriginaladdress nvarchar(255) not null

hm_drop_table_objects 'hm_imapfolders'

alter table hm_imapfolders alter column foldername nvarchar(255) not null

ALTER TABLE hm_imapfolders ADD CONSTRAINT hm_imapfolders_pk PRIMARY KEY NONCLUSTERED (folderid) 

CREATE CLUSTERED INDEX idx_hm_imapfolders_folderaccountid ON hm_imapfolders (folderaccountid)  

ALTER TABLE hm_imapfolders ADD CONSTRAINT idx_hm_imapfolders_unique UNIQUE NONCLUSTERED (folderaccountid, folderparentid, foldername)

hm_drop_table_objects 'hm_routes'

alter table hm_routes alter column routedomainname nvarchar(255) not null

alter table hm_routes alter column routetargetsmthost nvarchar(255) not null

alter table hm_routes alter column routeauthenticationusername nvarchar(255) not null

alter table hm_routes alter column routeauthenticationpassword nvarchar(255) not null

ALTER TABLE hm_routes ADD CONSTRAINT hm_routes_pk PRIMARY KEY NONCLUSTERED (routeid) 

ALTER TABLE hm_routes ADD CONSTRAINT u_routedomainname UNIQUE NONCLUSTERED (routedomainname) 

alter table hm_routeaddresses alter column routeaddressaddress nvarchar(255) not null

alter table hm_dnsbl alter column sbldnshost nvarchar(255) not null

alter table hm_dnsbl alter column sblresult nvarchar(255) not null

alter table hm_dnsbl alter column sblrejectmessage nvarchar(255) not null

alter table hm_fetchaccounts alter column faaccountname nvarchar(255) not null

alter table hm_fetchaccounts alter column faserveraddress nvarchar(255) not null

alter table hm_fetchaccounts alter column fausername nvarchar(255) not null

alter table hm_fetchaccounts alter column fapassword nvarchar(255) not null

alter table hm_fetchaccounts_uids alter column uidvalue nvarchar(255) not null

alter table hm_rule_criterias alter column criteriaheadername nvarchar(255) not null

alter table hm_rule_criterias alter column criteriamatchvalue nvarchar(255) not null

alter table hm_rule_actions alter column actionimapfolder nvarchar(255) not null

alter table hm_rule_actions alter column actionfromaddress nvarchar(255) not null

alter table hm_rule_actions alter column actionscriptfunction nvarchar(255) not null

alter table hm_rule_actions alter column actionheader nvarchar(255) not null

alter table hm_surblservers alter column surblhost nvarchar(255) not null

alter table hm_surblservers alter column surblrejectmessage nvarchar(255) not null

hm_drop_table_objects 'hm_greylisting_triplets'

alter table hm_greylisting_triplets alter column glsenderaddress nvarchar(200) not null

alter table hm_greylisting_triplets alter column glrecipientaddress nvarchar(200) not null

ALTER TABLE hm_greylisting_triplets ADD CONSTRAINT hm_glid_pk PRIMARY KEY NONCLUSTERED (glid) 

ALTER TABLE hm_greylisting_triplets ADD CONSTRAINT u_gltriplet UNIQUE NONCLUSTERED (glipaddress1, glipaddress2, glsenderaddress, glrecipientaddress) 

hm_drop_table_objects 'hm_greylisting_whiteaddresses'

alter table hm_greylisting_whiteaddresses alter column whiteipaddress nvarchar(255) not null

ALTER TABLE hm_greylisting_whiteaddresses ADD CONSTRAINT hm_glwhite_pk PRIMARY KEY NONCLUSTERED (whiteid) 

ALTER TABLE hm_greylisting_whiteaddresses ADD CONSTRAINT u_glwhite UNIQUE NONCLUSTERED (whiteipaddress) 

alter table hm_servermessages alter column smname nvarchar(255) not null

alter table hm_whitelist alter column whiteemailaddress nvarchar(255) not null

alter table hm_whitelist alter column whiteemailaddress nvarchar(255) not null

insert into hm_settings (settingname, settingstring, settinginteger) values ('EnableWhitelisting', '', 1)

update hm_whitelist set whiteemailaddress = replace(whiteemailaddress, '/', '//')

update hm_whitelist set whiteemailaddress = replace(whiteemailaddress, '%', '/%')

update hm_whitelist set whiteemailaddress = replace(whiteemailaddress, '_', '/_')

update hm_whitelist set whiteemailaddress = replace(whiteemailaddress, '?', '_')

update hm_whitelist set whiteemailaddress = replace(whiteemailaddress, '*', '%')

update hm_greylisting_whiteaddresses set whiteipaddress = replace(whiteipaddress, '/', '//')

update hm_greylisting_whiteaddresses set whiteipaddress = replace(whiteipaddress, '%', '/%')

update hm_greylisting_whiteaddresses set whiteipaddress = replace(whiteipaddress, '_', '/_')

update hm_greylisting_whiteaddresses set whiteipaddress = replace(whiteipaddress, '?', '_')

update hm_greylisting_whiteaddresses set whiteipaddress = replace(whiteipaddress, '*', '%')

delete from hm_settings where settingname = 'tarpitdelay'

delete from hm_settings where settingname = 'tarpitcount'

insert into hm_settings (settingname, settingstring, settinginteger) values ('MaxNumberOfMXHosts', '', 15)

update hm_dbversion set value = 5400

