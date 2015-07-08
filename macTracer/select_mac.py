import sqlite3
import json
import urllib2

conn = sqlite3.connect('/home/utku/summerseed/internetTracer/sniffer/data/sniff.sqlite')
c = conn.cursor()

c.execute('select ("wlan.ta") from packets group by "wlan.ta"')

info_list = []
my_json = []
pack_list = c.fetchall()

for row in pack_list:
	a = str(row)
	a = a.replace("(u\'","")
	a = a.replace("\',)","")
	req = urllib2.Request("http://www.macvendorlookup.com/api/v2/%s" % (a))
	opener = urllib2.build_opener()
	f = opener.open(req)
	info_list = f.read()
	print "*********"
	
	if len(info_list) > 0:
		my_json = json.loads(info_list)
		print str(my_json[0]["company"])
	
	#print json[0]['company']
