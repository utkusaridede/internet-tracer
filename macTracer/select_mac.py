import sqlite3
import json
import urllib2

fSignal = open("data/signals", "a")
fopen = open("data/company", "a")
fPackets = open("data/packetSizes", "a")

def getVendorByMacAddress(packList):
    for row in packList:
        signalStrength = str(row[3])
        macAddress = str(row[2])
        macAddress = macAddress.replace("(u\'", "")
        macAddress = macAddress.replace("\',)", "")
        packetSize = row[0] - row[1]
        req = urllib2.Request("http://www.macvendorlookup.com/api/v2/%s" % (macAddress))
        opener = urllib2.build_opener()
        f = opener.open(req)
        info_list = f.read()
	
        if len(info_list) > 0:
            my_json = json.loads(info_list)
            fopen.write(str(my_json[0]["company"]))
            fPackets.write(macAddress + ", (" + str(my_json[0]["company"])+ ")|" + str(packetSize))
            fopen.write("\n")
            fPackets.write("\n")
            fSignal.write(macAddress + ", (" + str(my_json[0]["company"])+  ")|" + signalStrength)
            fSignal.write("\n")

fo = open("data/sniffFileCount.txt","r")
count = fo.read()
count = int(count)
fo.close()

if count == 1:
    count += 1

for x in xrange(1, count):
    conn = sqlite3.connect("../sniffer/data/sniff%d.sqlite" % x)
    c = conn.cursor()
    c.execute('select sum("frame.len"),sum("radiotap.length"),("wlan.ta"), AVG("radiotap.dbm_antsignal") from packets group by "wlan.ta"')
    info_list = []
    my_json = []
    pack_list = c.fetchall()
    getVendorByMacAddress(pack_list)
    conn.close()

fopen.close()
fSignal.close()
fPackets.close()
