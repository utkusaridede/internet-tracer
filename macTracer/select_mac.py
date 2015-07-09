import sqlite3
import json
import urllib2


def getVendorByMacAddress(packList):
    for row in packList:
        macAddress = str(row[2])
        macAddress = macAddress.replace("(u\'", "")
        macAddress = macAddress.replace("\',)", "")
        packetSize = row[0] - row[1]
        req = urllib2.Request("http://www.macvendorlookup.com/api/v2/%s" % (macAddress))
        opener = urllib2.build_opener()
        f = opener.open(req)
        info_list = f.read()
        print "*********"

        if len(info_list) > 0:
            my_json = json.loads(info_list)
            print packetSize, macAddress,str(my_json[0]["company"])


conn = sqlite3.connect(
    '/home/utku/summerseed/internetTracer/sniffer/data/sniff.sqlite')
c = conn.cursor()
c.execute('select sum("frame.len"),sum("radiotap.length"),("wlan.ta") from packets group by "wlan.ta"')
info_list = []
my_json = []
pack_list = c.fetchall()
getVendorByMacAddress(pack_list)
