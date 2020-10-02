import requests
import json
import time
import itertools
import csv

headers1 = {
            'authority': 'www.baanfinder.com',
            'accept': 'application/json, text/javascript, */*; q=0.01',
            'sec-fetch-dest': 'empty',
            'x-requested-with': 'XMLHttpRequest',
            'user-agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.100 Safari/537.36',
            'sec-fetch-site': 'same-origin',
            'sec-fetch-mode': 'cors',
            'referer': 'https://www.baanfinder.com/new',
            'accept-language': 'en-US,en;q=0.9',
            'cookie': '__cfduid=da90128fba9f926e25d906fde02de60851590347982; _ga=GA1.2.1128504173.1590347986; _gid=GA1.2.1813785111.1590347986; _fbp=fb.1.1590347987258.985526683; _cbclose=1; _cbclose57999=1; _uid57999=D81A2BC1.1; _ctout57999=1; verify=test; intercom-id-o7ricfx2=f549c146-f3e6-4436-9f91-e7b77406c3f9; G_ENABLED_IDPS=google; BF_SESSION=88835b7aaa856fb4134ae0d0623f838319f09742-___AT=2ce1fb4c9dd33c68bd996708edbeff3f8dae2a5a&username=95m7bzxqxq5d5chv1agyf4nv1pvvltqd2qfkov7t; rememberme=eef961823672943e8e661041c225c333820e0d8c-95m7bzxqxq5d5chv1agyf4nv1pvvltqd2qfkov7t-1592940454237; BF_FLASH=url=%2F; _gat=1; intercom-session-o7ricfx2=TlNYVWp2WGl4bWpYN1pLNWh6QjdNNm5ScWx0c2FySjlhaWxxTWV6NXpOY25QalFOVWxjd2l3bGl0cHMxdE1aNS0tRTF0K0N3dzYvbk9NN1Frd3F2ck9pUT09--c12a7731358599cc1526640e5d69e967b0f4ac05',
        }

def iterate_eng(current):
        print(current)
        paramss = (
            ('search', current),
        )
        response = requests.get('https://www.baanfinder.com/api/search/projects/alphabet', headers=headers1, params=paramss)
        json_data = json.loads(response.text)
        for jd in json_data:
                final_list.append(jd)
        if(len(json_data)==10):
            for ch in eng_char:
                temp=current+ch
                iterate_eng(temp)



def iterate_thai(current):
        print(current)
        paramss = (
            ('search', current),
        )
        response = requests.get('https://www.baanfinder.com/api/search/projects/alphabet', headers=headers1, params=paramss)
        json_data = json.loads(response.text)
        for jd in json_data:
                final_list.append(jd)
        if(len(json_data)==10):
            for ch in thai_char:
                temp=current+ch
                iterate_thai(temp)



thai_char = ['ก', 'ข', 'ค', 'ฆ', 'ง', 'จ', 'ฉ', 'ช', ' ซ', 'ฌ', 'ญ', 'ฎ', 'ฏ', 'ฐ', 'ฑ', 'ฒ', 'ณ', 'ด', 'ต', 'ถ', 'ท', 'ธ', 'น', 'บ', 'ป', 'ผ', 'ฝ', 'พ', 'ฟ', 'ภ', 'ม', 'ย', 'ร', 'ล', 'ว', 'ศ', 'ษ', 'ส', 'ห', 'ฬ', 'อ', 'ฮ']
eng_char = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']



# cr=""
# iterate_thai(cr)
# for cr in eng_char:
final_list=[]
iterate_eng('a')
f=open('baanfinder.txt',"a+")
for ele in final_list:
    f.write(ele)




print("Scraping Done!!")

out_list=[]
for ele in final_list:
    if ele not in out_list:
        out_list.append(ele)
'''
out_dict={}
with open("baanfinder.csv", "w", newline="", encoding='utf-8') as f:
    writer = csv.writer(f, delimiter =';')
    writer.writerows(out_list)

for ele in out_list:
    out_dict[ele['id']]={'textSecondary':ele['textSecondary'], 'provinceLocalized': ele['provinceLocalized'], 'districtLocalized':ele['districtLocalized'], 'id': ele['id'], 'text': ele['text']}
'''

ddteedin_result = open("baanfinder_result.json", "w")
ddteedin_result.write((json.dumps(out_list, indent=4, sort_keys=True)))
ddteedin_result.close()