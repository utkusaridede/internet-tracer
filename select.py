import sqlite3
import json
import urllib2

conn = sqlite3.connect('/home/utku/summerseed/internetTracer/sniffer/data/sniff.sqlite')
c = conn.cursor()


for row in c.execute('select ("wlan.ta") from packets group by "wlan.ta"'):
	a = row[0][0:17]
	req = urllib2.Request("http://www.macvendorlookup.com/api/v2/%s" % (a))
	opener = urllib2.build_opener()
	f = opener.open(req)
	json = json.loads(f.read())
	print json[0]['company']
