# -*- coding:utf-8 -*-
import mechanize
import cookielib

def viewPage(url):
    browser = mechanize.Browser()
    browser.set_handle_robots(False)
    browser.set_handle_equiv(False)
    page = browser.open(url)
    source_code = page.read()
    print source_code

def testProxy(url, proxy):
    browser = mechanize.Browser()
    cj = cookielib.LWPCookieJar()
    browser.set_cookiejar(cj)
    browser.set_handle_equiv(True)
    browser.set_handle_redirect(True)
    browser.set_handle_robots(False)
    browser.addheaders = [('User-agent','Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/28.0.1500.72 Safari/537.36')]
    # browser.addheaders = [('User-agent', 'Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.0.1) Gecko/2008071615 Fedora/3.0.1-1.fc9 Firefox/3.0.1')]
    browser.set_proxies(proxy)
    page = browser.open(url)
    source_code = page.read()
    print source_code

url = 'http://127.0.0.1:8000'
prox = '212.193.133.72:8080'
proxy = {'http': prox}
testProxy(url, proxy)
# viewPage(url)
