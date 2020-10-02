import requests
import json
import time
import itertools
import csv
import re


def run():
    thai_char = ['ก', 'ข', 'ค', 'ฆ', 'ง', 'จ', 'ฉ', 'ช', ' ซ', 'ฌ', 'ญ', 'ฎ', 'ฏ', 'ฐ', 'ฑ', 'ฒ', 'ณ', 'ด', 'ต', 'ถ', 'ท', 'ธ', 'น', 'บ', 'ป', 'ผ', 'ฝ', 'พ', 'ฟ', 'ภ', 'ม', 'ย', 'ร', 'ล', 'ว', 'ศ', 'ษ', 'ส', 'ห', 'ฬ', 'อ', 'ฮ']
    eng_char = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    # thai_char = [ 'ส']
    all_char = thai_char + eng_char

    master_dict = {}

    data = []

    # eng_char = ['a', 'b']

    for idx, char in enumerate(eng_char):
        # time.sleep(5)

        print(idx, ": ", char)

        # flag = True

        # while flag:
        response = requests.get('http://www.prakardproperty.com/autocomplete/project/?term=' + char)
        
        # print(response.text)
        list_data = json.loads(response.text, strict = False)
        
        print(len(list_data))
        for record in list_data:

            rec = []

            key = record["value"]

            # if key not in master_dict:
            #     master_dict[key] = {}

            master_dict[key] = {
                "name" : key,

                "province_id" : record["province_id"],
                "district_id" : record["district_id"],
                "subdistrict_id" : record["sub_district_id"],
                "latitude" : record["google_map_latitude"],
                "longitude" : record["google_map_longitude"]
            }


            # results = re.findall('\(.*\)', key)

            # if len(results) > 0:
            #     name_th = results[0].strip()[1:-1]
            # else:
            #     name_th = ""
            
            # name_en = re.sub('\(.*\)', "", key).strip()
            
            rec = [key, master_dict[key]["province_id"], master_dict[key]["district_id"], master_dict[key]["subdistrict_id"], master_dict[key]["latitude"], master_dict[key]["longitude"] ]
            data.append(rec)

    data.sort()
    data = list(k for k,_ in itertools.groupby(data))

    with open("prakardproperty.csv", "w", newline="", encoding='utf-8') as f:
        writer = csv.writer(f, delimiter =';')
        writer.writerows(data)

    # prakardproperty_result = open("prakardproperty_result.json", "w")
    # prakardproperty_result.write((json.dumps(master_dict, indent=4, sort_keys=True)))
    # prakardproperty_result.close()
