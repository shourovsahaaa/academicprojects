Author: Shourov Saha,
Co-Contributer: James Ng
<h1>Steps to create an Ubuntu Interface with Azure</h1>
<h2>Step 1: Create an Azure Account.</h2>
Navigate to: https://azure.microsoft.com/en-us/ and create your account.

<h2>Step 2: Setting up a server.</h2>
1. To set up, either type in “Virtual Machines” on the search bar or navigate to the Virtual machine icon on the homepage and click “Create”.

2. Leave the resource group empty, so deleting the VM wouldn't interfere with any other unaffiliated groups.

3. Leave all the unrequired parameters, ones marked without a red ‘*’, empty.

4. Give your instance a name to view it on your Azure Account, choose your preferred server location, and under “Image,” chose “Ubuntu Server 22.04 LTS - Gen2”.
Using a spot instance would allow hourly use of the server and possibly reduce costs, however, is not supported by all sizes.
( For this guide, we will choose Standard DS1_v2. ) 

5. Under “Authentication Type,” choose “Password” and create a username and password for your VM. You will need this to access your VM.

6. For the “Inbound port rules”, allow selected ports, and in the dropdown menu, HTTP, HTTPS, and SSH should be enabled. If not, you can go into the networking tab in your VM on Azure and set up these forwarding rules manually.

7. Click "Review + Create", followed by "Create".


<h2>Step 3: Connecting to the server.</h2>

1. To connect to the server, you must have access to a Linux system or a subsystem. If on Windows, use the Linux Subsystem for Windows, Ubuntu. 
Only for Windows users, steps to download Ubuntu can be found here: https://ubuntu.com/tutorials/install-ubuntu-on-wsl2-on-windows-10#1-overview

2. To find the IP address for your machine, locate your virtual machine by typing in Virtual Machines in the Azure Search bar and navigating to the name you entered during setup. Defaulting in the overview tab, the IP address can be found next to the “Public IP address”. In the terminal, enter the following command:
```
ssh [username]@[IP]
```
&emsp;&emsp;filling in the brackets with the username entered during setup, and the IP located in the overview.

4. Enter Y and use the default fingerprint.
*If you would like to be secure and create your own fingerprint, you may do so by following this link: https://docs.microsoft.com/en-us/azure/virtual-machines/linux-vm-connect?tabs=Linux

**You should now be connected!**


<h2>Step 4 (Optional): Setting up a desktop environment for your VM (on Windows).</h2>

1. First we must install a desktop environment on our VM.
Enter the following command to connect to your server using your password (Skip this step if you are already connected):
```
ssh [username]@[IP]
```
&emsp;&emsp;Then, use the following commands to download the required packages for a Desktop Environment:
```
sudo apt-get update
sudo DEBIAN_FRONTEND=noninteractive apt-get -y install xfce4
sudo apt install xfce4-session
```
&emsp;&emsp;Install the packages using the following commands:
```
sudo apt-get -y install xrdp
sudo systemctl enable xrdp
```
&emsp;&emsp;Configure the packages by entering the following command:
```
echo xfce4-session >~/.xsession
```
&emsp;&emsp;And restart the service with the following command:
```
sudo service xrdp restart
```

2. Now we must set up port forwarding rules to access the server. Navigate to the Networking tab of your VM on Azure. Locate “Add inbound port rule” to add a rule and leave everything default except “Destination port ranges” and set that to “3389” and the “Name” which you could set to anything, but for this guide, we will name it “RDP_Port”. 

3. Return to the overview of your VM on Azure. Locate the dropdown menu under “Connect” and click on “RDP” (Remote Desktop Protocol). Make sure your “Public IP Address ([IP])” is selected and the port is set to its forwarded value, “3389”. Download the RDP file and after executing, you will be able to use your username and credentials to log into the VM’s desktop environment.
