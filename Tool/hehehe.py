import urllib.request
import urllib.parse
import gzip
import os

def mstr(t,s,e):
    return t.split(s)[1].split(e)[0]
def ungzip(data):
    try:
        data=gzip.decompress(data)
    except:
        pass
    return data

head='''
Host: atcoder.jp
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:132.0) Gecko/20100101 Firefox/132.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2
Accept-Encoding: deflate, br, zstd
Referer: https://atcoder.jp/contests/abc380/submissions?f.LanguageName=&f.Status=AC&f.Task=abc380_e&f.User=&page=31
Connection: keep-alive
Cookie: 【填你自己的】
Upgrade-Insecure-Requests: 1
Sec-Fetch-Dest: document
Sec-Fetch-Mode: navigate
Sec-Fetch-Site: same-origin
Sec-Fetch-User: ?1
Priority: u=0, i
Pragma: no-cache
Cache-Control: no-cache
'''.split('\n')
mp_at={}
for t in head:
    if t=='':continue
    a,b=t.split(": ")
    mp_at[a]=b

def read(url,hd):
    #url = 'https://codeforces.com/problemset/'
    request =urllib.request.Request(url,headers=hd, method = 'GET')
    response = urllib.request.urlopen(request)
    #print("Decoding...")
    #log=ungzip(response.read())
    log=response.read().decode()
    #print("Ok")
    return log

def fix(t):
    return t.replace("&lt;","<").replace("&gt;",">").replace("&#39;","'").replace("&quot;",'"').replace("&amp;","&")

#匹配串
check = "n,Q,type,x,c,fa[500010],co[500010],k,tem,tem2;"
#check = "0x0F0F0F0F0F0F0F0F"
def ck(s):
    return s.find(check) != -1

for page in range(45, 135):
    print("Searching in the page of " + str(page) + "...")
    t = read("https://atcoder.jp/contests/abc380/submissions?f.LanguageName=&f.Status=AC&f.Task=abc380_e&f.User=&page=" + str(page), mp_at)
    t = mstr(t, 'table table-bordered table-striped small th-center', "</table>")
    t = mstr(t, "<tbody>", "</tbody>")

    for content in t.split("</tr>")[:-1]:
        tmp = mstr(content, "/contests/abc380/submissions/", '"')
        print("Looking up for the submission of " + tmp + "...")

        sub = read("https://atcoder.jp/contests/abc380/submissions/" + tmp, mp_at)
        if ck(sub):
            print("FIND!!")
            exit(0)


'''
Looking up for the submission of 59868856...
Looking up for the submission of 59868847...
Searching in the page of 53...
Looking up for the submission of 59868847...
Looking up for the submission of 59868845...
Looking up for the submission of 59868809...
Looking up for the submission of 59868806...
Looking up for the submission of 59868802...
Looking up for the submission of 59868765...
Looking up for the submission of 59868764...
Looking up for the submission of 59868760...
Looking up for the submission of 59868757...
Looking up for the submission of 59868752...
Looking up for the submission of 59868747...
Looking up for the submission of 59868740...
Looking up for the submission of 59868727...
Looking up for the submission of 59868725...
FIND!!
'''