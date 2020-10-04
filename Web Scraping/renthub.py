import requests
import json
import time
import itertools
import csv

cookies = {
    '_ga': 'GA1.3.1353274546.1591507195',
    '_gid': 'GA1.3.799124246.1591507195',
    '_cbclose': '1',
    '_cbclose56220': '1',
    '_uid56220': 'D274B525.1',
    '_ctout56220': '1',
    'user_uuid': '68c2ec65-957a-45bc-bd2b-1a1f08cf0244',
    'verify': 'test',
    'remember_user_token': 'BAhbB1sGaQNyBgNJIhk5OWl5dUVDcWh0VWZ5dkdKQjdoQQY6BkVU--03b02038feac243ff9dc3c0f5446fc039ee59724',
    '_renthub_session': 'dede9019d0dcd7de7657f171f1db6798',
    'user_identity_v3': 'lesawib--https%3A%2F%2Fcdn.renthub.in.th%2Fassets%2Fnoavatar32-268531855014e2311cf9709944cb41ec.png--lesawib674%40dffwer.com--0987654321--1590968201--false--198258--94d4731d8eec53334a51473e212a7bea497d30f9439f340e3f5fdf1f1051d945',
    'user_favorites': '%5B%5D--%5B%5D',
    '_gat': '1',
    'DO-LB-v5': 'node-169527480|Xtx6S|Xtx5z',
}

headers = {
    'Connection': 'keep-alive',
    'Accept': '*/*',
    'DNT': '1',
    'X-CSRF-Token': 'Wey4LyoQlPrmt4dytmthqRB7EHUOo8YNZp2122IfjNU=',
    'X-Requested-With': 'XMLHttpRequest',
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3904.97 Safari/537.36',
    'Sec-Fetch-Site': 'same-origin',
    'Sec-Fetch-Mode': 'cors',
    'Referer': 'https://renthub.in.th/condo_listings/new',
    'Accept-Encoding': 'gzip, deflate, br',
    'Accept-Language': 'en-US,en;q=0.9',
}

eng_char = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
thai_char = ['ก', 'ข', 'ค', 'ฆ', 'ง', 'จ', 'ฉ', 'ช', ' ซ', 'ฌ', 'ญ', 'ฎ', 'ฏ', 'ฐ', 'ฑ', 'ฒ', 'ณ', 'ด', 'ต', 'ถ', 'ท', 'ธ', 'น', 'บ', 'ป', 'ผ', 'ฝ', 'พ', 'ฟ', 'ภ', 'ม', 'ย', 'ร', 'ล', 'ว', 'ศ', 'ษ', 'ส', 'ห', 'ฬ', 'อ', 'ฮ']
final_list=[]


def iterate_eng(current):
        print(current)
        params = (('name', current),)
        response = requests.get('https://renthub.in.th/condo_listings/search_project', headers=headers, params=params, cookies=cookies)
        json_data = json.loads(response.text)
        for jd in json_data:
                final_list.append(jd)
        # print(len(json_data))
        if(len(json_data)==100):
            for ch in eng_char:
                temp=current+ch
                iterate_eng(temp)

def iterate_thai(current):
        print(current)
        params = (('name', current),)
        response = requests.get('https://renthub.in.th/condo_listings/search_project', headers=headers, params=params, cookies=cookies)
        json_data = json.loads(response.text)
        for jd in json_data:
                final_list.append(jd)
        # print(len(json_data))
        if(len(json_data)==100):
            for ch in eng_char:
                temp=current+ch
                iterate_thai(temp)


def run():
  
  for c in eng_char:
    iterate_eng(c)
    
  for c in thai_char:
    iterate_thai(c)

  ol=[]

  for ele in final_list:
    if ele not in ol:
      ol.append(ele)

  f=open('renthub.json','w')
  f.write(json.dumps(ol))
  f.close()

  cs=open('renthub.csv','w+')
  for ele in final_list:
    cs.write(ele['id']+';'+ele['name']+';'+ele['address']+'\n')

  cs.close()

  l=f.read()
  l=l.split('\n')

  cs=open('renthub.csv','w+')
  cs.write('id;name;name_en;name_th;address\n')

  for ele in final_list:
    try:
        if line[1].find(') (')>-1:
            line[1]=line[1].replace(') (',');(')
            out.write(line[0]+';'+line[1]+';;;'+line[2]+'\n')
        else:
            out.write(line[0]+';'+line[1]+';'+line[1].split('(')[0]+';'+line[1].split('(')[1].replace(')','')+';'+line[2]+'\n')
    except:
          print(ele)

