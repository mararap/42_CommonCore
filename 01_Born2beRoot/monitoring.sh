#!/bin/bash

#At server startup, the script will display some information (listed below) on 
#all terminals and every 10 minutes (take a look at wall). The banner is optional.
#No error must be visible.
#Your script must always be able to display the following information:
#• The architecture of your operating system and its kernel version.
#• The number of physical processors.
#• The number of virtual processors.
#• The current available RAM on your server and its utilization rate as a percentage.
#• The current available storage on your server and its utilization rate as a percentage.
#• The current utilization rate of your processors as a percentage.
#• The date and time of the last reboot.
#• Whether LVM is active or not.
#• The number of active connections.
#• The number of users using the server.
#• The IPv4 address of your server and its MAC (Media Access Control) address.
#• The number of commands executed with the sudo program.
#example output:
#Broadcast message from root@marapovi42 (tty1(?)) (Mon Jul 25 15:54:00):
#	#Architecture: Linux wil .....
#	#CPU phzsical : 1
#	#vCPU : 1
#	#Memory Usage : 74/987MB (..%)
#	#Disk Usage: 1009/2GB (..%)
#	#CPU load: 6.7%
#	#Last Boot: 2021-04-25 14:45
#	#LVM use: yes
#	#Connections TOP : 1 ESTABLISHED
#	#User log: 1
#	#Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
#	#Sudo : 42 cmd

chmod 700 ~/CommonCore_gh/01_Born2beRoot/monitoring.sh #user rights
head -n 2 /etc/os-release #
/home/marapovi42 /usr/sbin/aa-status
/home/marapovi42 ss -tunlp
/home/marapovi42 /usr/sbin/ufw status
