# For testing re
# created by wei
# Aug 22, 2023
import re


text = r'<seg id="10">＜2日目の日本勢成績＞ 2T ／ － 9／米澤蓮 5T ／ － 5／桂川有人 12T ／ － 3／金谷拓実、中島啓太 16T ／ － 2／吉原英駿 59T／＋9／青島賢吾</seg>'

# Define the regular expression pattern
pattern = r"<seg id=\"\d+\">(.*)<\/seg>"

# group(1) get the first result in brackets
new_text = re.search(pattern, text)



# Print the result
if new_text:
    print(new_text.group(1))
else:
    print("No match")