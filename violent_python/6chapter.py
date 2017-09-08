# -*- coding:utf-8 -*-
import mechanize
import cookielib

def viewPage(url):
    browser = mechanize.Browser()
    page = browser.open(url)
    source_code = page.read()
    print source_code

def testProxy(url, proxy):
    browser = mechanize.Browser()
    browser.set_handle_robots(False)
    browser.set_proxies(proxy)
    page = browser.open(url)
    source_code = page.read()
    print source_code

def testUserAgent(url,userAgent):
    browser = mechanize.Browser()
    browser.addheaders = userAgent
    page = browser.open(url)
    source_code = page.read()
    print source_code

def printCookies(url):
    browser = mechanize.Browser()
    browser.set_handle_robots(False)
    cookie_jar = cookielib.LWPCookieJar()
    browser.set_cookiejar(cookie_jar)
    page = browser.open(url)
    for cookie in cookie_jar:
        print cookie

url = 'https://www.whatismybrowser.com/detect/what-is-my-user-agent'
userAgent = [('User-agent', 'Mozilla/5.0 (Diegosh; Intel Mac OS X'+\
              ' 10_10_1) AppleWebKit/537.36 (KHTML, like Gecko'+\
              ') Chrome/41.0.2227.1 Safari/537.36')]
url = 'http://whatismyip.com.br/'
# proxy = {'http': '119.6.136.122:83'}
# viewPage(url)
# testProxy(url, proxy)
# testUserAgent(url,userAgent)
# printCookies(url)

from chapter6_anonclass import *
ab = anonBrowser(proxies=[],\
user_agents=[('User-agent','superSecretBroswer')])
for attempt in range(1, 5):
    ab.anonymize()
    print '[*] Fetching page'
    response = ab.open('http://kittenwar.com')
    for cookie in ab.cookie_jar:
        print cookie
