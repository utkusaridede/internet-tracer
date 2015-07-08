import json
import urllib2


req = urllib2.Request("http://www.macvendorlookup.com/api/v2/38:2d:d1:aa:f2:58")
opener = urllib2.build_opener()
f = opener.open(req)
json = json.loads(f.read())
print json
print json[0]['company']

