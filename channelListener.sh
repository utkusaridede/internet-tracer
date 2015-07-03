#!/bin/bash
cd sniffer
cd input
sudo rm ekraninkokusu.pcap
sudo ifconfig wlan0 down
sudo iwconfig wlan0 mode monitor
sudo ifconfig wlan0 up
sudo iwconfig wlan0 channel 10
sudo timeout 10 tcpdump -i wlan0 -n -s 64 -w ekraninkokusu.pcap
sudo ifconfig wlan0 down
sudo iwconfig wlan0 mode managed
sudo ifconfig wlan0 up
sudo dhclient wlan0