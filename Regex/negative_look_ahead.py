#Lines that not include word "hede":
import re

regex = '^((?!{0}).)*$'; # another version which is lookbehind ^(.(?<!hede))*$

print ("Enter a word to find lines that exclude:");
exclude = raw_input();
print ("Enter line to determine if include enetered value:");

while True:
    line = raw_input();
    regex = regex.format(exclude);
    pattern = re.compile(regex);
    if pattern.match(line):
        print("Does not include in anywhere")
    else:
        print ("Includes")



line = raw_input();
regex = regex.format(exclude);
if re.findall(regex, line):
    print("Does not include",re.findall(regex, line))
else:
    print ("Includes", re.findall(regex, line))


        