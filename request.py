import json
import urllib2

#req = urllib2.Request("http://www.macvendorlookup.com/api/v2/10:bf:48:1c:94:55")
req = urllib2.Request("http://www.macvendorlookup.com/api/v2/b8:b4:2e:c4:4a:21")
opener = urllib2.build_opener()
f = opener.open(req)
json = json.loads(f.read())
print json
print json[0]['company']

