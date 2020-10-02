import requests
import json
import time
import itertools
import csv

thai_char = ['ก', 'ข', 'ค', 'ฆ', 'ง', 'จ', 'ฉ', 'ช', ' ซ', 'ฌ', 'ญ', 'ฎ', 'ฏ', 'ฐ', 'ฑ', 'ฒ', 'ณ', 'ด', 'ต', 'ถ', 'ท', 'ธ', 'น', 'บ', 'ป', 'ผ', 'ฝ', 'พ', 'ฟ', 'ภ', 'ม', 'ย', 'ร', 'ล', 'ว', 'ศ', 'ษ', 'ส', 'ห', 'ฬ', 'อ', 'ฮ']
eng_char = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
# thai_char = [ 'ส']
all_char = eng_char + thai_char

master_dict = {}
data = []

local_data = {}

data.append(["Object_id", "Name"])


def make_request(query):

    print(query)

    data = {
        'query': query
    }

    response = requests.post('https://bankumka.com/ajax/listproject/', data=data)

    json_data = json.loads(response.text)
    # print(len(json_data))
    # print(json_data)

    list_data = json_data["suggestions"]

    for record in list_data:
        key = record["data"]

        if key not in local_data:
            local_data[key] = {}

        local_data[key] = {
            "object_id" : key,
            "name" : record["value"],
        }
    
    if len(list_data) == 30:
        for c in eng_char:
            make_request(query + c)

    # else:

    #     last_char = query[-1]
        
    #     if last_char == 'z':
    #         return

def run():
    
    for idx, char in enumerate(['a']):
        # time.sleep(5)

        # print(idx, ": ", char)

        local_data = {}
        make_request(char)

        # print(json.dumps(local_data, indent=4, sort_keys=True))
        # print(len(local_data))

        for key in local_data.keys():
            master_dict[key] = {
                "object_id" : key,
                "name" : local_data[key]["name"]
            }

            rec = [master_dict[key]["object_id"], master_dict[key]["name"]]
            data.append(rec) 
    data.sort()
    data = list(k for k,_ in itertools.groupby(data))
    with open("outb.csv", "w", newline="", encoding='utf-8') as f:
        writer = csv.writer(f, delimiter =';')
        writer.writerows(data)
    bankumka_result = open("bankumka_resultb.json", "w")
    bankumka_result.write((json.dumps(master_dict, indent=4, sort_keys=True)))
    bankumka_result.close()
