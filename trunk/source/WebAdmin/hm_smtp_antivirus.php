<?php
if (!defined('IN_WEBADMIN'))
   exit();

if (hmailGetAdminLevel() != 2)
	hmailHackingAttemp();

$obSettings	= $obBaseApp->Settings();
$obAntivirus	= $obSettings->AntiVirus();

$action	   = hmailGetVar("action","");

$str_delete = $obLanguage->String("Remove");

if($action == "save")
{
	$obAntivirus->Action            = hmailGetVar("avaction",0);
	$obAntivirus->NotifySender      = hmailGetVar("avnotifysender",0);
	$obAntivirus->NotifyReceiver    = hmailGetVar("avnotifyreceiver",0);
	$obAntivirus->MaximumMessageSize = hmailGetVar("MaximumMessageSize",0);
   
	$obAntivirus->ClamWinEnabled    = hmailGetVar("clamwinenabled",0);
	$obAntivirus->ClamWinExecutable = hmailGetVar("clamwinexecutable",0);
	$obAntivirus->ClamWinDBFolder   = hmailGetVar("clamwindbfolder",0);
	
	$obAntivirus->CustomScannerEnabled    = hmailGetVar("customscannerenabled",0);
	$obAntivirus->CustomScannerExecutable = hmailGetVar("customscannerexecutable",0);
	$obAntivirus->CustomScannerReturnValue = hmailGetVar("customscannerreturnvalue",0);	
	
   $obAntivirus->EnableAttachmentBlocking = hmailGetVar("EnableAttachmentBlocking",0);	
}



$avaction = $obAntivirus->Action;      
$avnotifysender = $obAntivirus->NotifySender;     
$avnotifyreceiver = $obAntivirus->NotifyReceiver;     
$MaximumMessageSize = $obAntivirus->MaximumMessageSize;     
 
$EnableAttachmentBlocking = $obAntivirus->EnableAttachmentBlocking;



$clamwinenabled    = $obAntivirus->ClamWinEnabled;     
$clamwinexecutable = $obAntivirus->ClamWinExecutable;     
$clamwindbfolder    = $obAntivirus->ClamWinDBFolder;     
   
$customscannerenabled    = $obAntivirus->CustomScannerEnabled;     
$customscannerexecutable = $obAntivirus->CustomScannerExecutable;     
$customscannerreturnvalue    = $obAntivirus->CustomScannerReturnValue;  

$avactiondeletemailchecked = hmailCheckedIf1($avaction == 0);
$avactiondeletattachmentschecked = hmailCheckedIf1($avaction == 1);
   
$clamwinenabledchecked = hmailCheckedIf1($clamwinenabled);
$customscannerenabledchecked = hmailCheckedIf1($customscannerenabled);
?>

<h1><?php EchoTranslation("Anti-virus")?></h1>

<form action="index.php" method="post" onSubmit="return formCheck(this);">

   <?php
      PrintHidden("page", "smtp_antivirus");
      PrintHidden("action", "save");
   ?>

   
   <div class="tabber">
      <div class="tabbertab">
         <h2><?php EchoTranslation("General")?></h2>       
   
      	<table border="0" width="100%" cellpadding="5">
         <tr>
            <th width="30%"></th>
            <th width="70%"></th>
         </tr>	
      	<tr>
      		<td><?php EchoTranslation("When a virus is found")?></td>
      		<td><input type="radio" name="avaction" value="0" <?php echo $avactiondeletemailchecked?>> <?php EchoTranslation("Delete e-mail")?></td>
      	</tr>  	
      	<tr>
      		<td></td>
      		<td><input type="radio" name="avaction" value="1" <?php echo $avactiondeletattachmentschecked?>> <?php EchoTranslation("Delete attachments")?></td>
      	</tr>	
         <?php
            PrintPropertyEditRow("MaximumMessageSize", "Maximum message size to virus scan (KB)", $MaximumMessageSize, 10);
         ?>
         </table>
      </div>
      
      <div class="tabbertab">
         <h2>ClamWin</h2>          
         <table border="0" width="100%" cellpadding="5">
         <tr>
            <th width="30%"></th>
            <th width="70%"></th>
         </tr>	

      	<tr>
      		<td><?php EchoTranslation("Enabled")?></td>
      		<td><input type="checkbox" name="clamwinenabled" value="1" <?php echo $clamwinenabledchecked?>></td>
      	</tr> 		
      	<tr>
      		<td><?php EchoTranslation("ClamScan executable")?></td>
      		<td><input type="text" name="clamwinexecutable" value="<?php echo PreprocessOutput($clamwinexecutable)?>" size="50"></td>
      	</tr>   
      	<tr>
      		<td><?php EchoTranslation("Path to ClamScan database")?></td>
      		<td><input type="text" name="clamwindbfolder" value="<?php echo PreprocessOutput($clamwindbfolder)?>"  size="50"></td>
      	</tr>  	
         </table>
      </div>

      <div class="tabbertab">
         <h2><?php EchoTranslation("External virus scanner")?></h2>        
         <table border="0" width="100%" cellpadding="5">
            <tr>
            <th width="30%"></th>
            <th width="70%"></th>
         </tr>	
      	<tr>
      		<td><?php EchoTranslation("Enabled")?></td>
      		<td><input type="checkbox" name="customscannerenabled" value="1" <?php echo $customscannerenabledchecked?>></td>
      	</tr> 		
      	<tr>
      		<td><?php EchoTranslation("Scanner executable")?></td>
      		<td><input type="text" name="customscannerexecutable" value="<?php echo PreprocessOutput($customscannerexecutable)?>" size="50"></td>
      	</tr>   
      	<tr>
      		<td><?php EchoTranslation("Return value")?></td>
      		<td><input type="text" name="customscannerreturnvalue" value="<?php echo PreprocessOutput($customscannerreturnvalue)?>"  size="4"></td>
      	</tr> 	
      </table>
     </div>
     
      <div class="tabbertab">
         <h2><?php EchoTranslation("Block attachments")?></h2>        
         <table border="0" width="400" cellpadding="5">
            <?php               
               PrintCheckboxRow("EnableAttachmentBlocking", "Block attachments with the following extensions:", $EnableAttachmentBlocking);
            ?>
         </table>
         
         <table border="0" width="400" cellpadding="5">
            <tr>
               <td><i><?php EchoTranslation("Name")?></i></td>
               <td><i><?php EchoTranslation("Description")?></i></td>
               <td><!-- delete column --></td>
            </tr>
            
               <?php
                  $blockedAttachments = $obAntivirus->BlockedAttachments;
                  
                  for ($i = 0; $i < $blockedAttachments->Count; $i++)
                  {
                     $blockedAttachment = $blockedAttachments->Item($i);
                     $id = $blockedAttachment->ID;
                     $wildcard = $blockedAttachment->Wildcard;
                     $description= $blockedAttachment->Description;
                     
                     ?>
                     <tr>
                        <td><a href="?page=blocked_attachment&action=edit&id=<?php echo $id?>"><?php echo PreprocessOutput($wildcard);?></a></td>                     
                        <td><?php echo PreprocessOutput($description);?></td>                     
                        <td>
                        <?php
                           echo "<a href=\"?page=background_blocked_attachment_save&action=delete&id=$id\">$str_delete</a>";
                        ?>
                        </td>                     
                     </tr>
                     <?php
                  }
               ?>            
         </table>
         <a href="?page=blocked_attachment&action=add"><i><?php EchoTranslation("Add")?></i></a>
      
     </div>     
    </div>
   <?php 
      PrintSaveButton();
   ?>

</form>