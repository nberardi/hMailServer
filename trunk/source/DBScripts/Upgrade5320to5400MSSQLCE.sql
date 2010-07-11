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

