#!/usr/bin/env python3

import sys
import datetime
import json
import os
import re
 
def delete(fname):
  # print("DELETE: "+os.getcwd())
  if os.path.exists(fname):
    os.chmod(fname, 0o777)
    os.remove(fname)

today = datetime.datetime.now().strftime("%d %B %Y")
#print(today)

cmd = "python3 " + sys.argv[0]
fullcmd = "python3 " + ' '.join(sys.argv)

usage="""
USAGE: {} TAG_FILE_MATHQ --chapters-and-headings CHAPTER1 ... [--branches CHAPTERS_THAT_HAVE_OWN_MAKEFILE1= ...] [--headings HEADER1= ...]

""".format(cmd)

N = len(sys.argv)

#help
if N >= 2 and sys.argv[1] == "--help": 
    print("\nHELP: {}\n".format(usage))
    sys.exit(1)


if N < 3: 
    print("\nInvalid number of command line arguments ({}): {}\n".format(n,cmd) + usage)
    sys.exit(1)


# grab tag file name
TAG_FILE = sys.argv[1]

if sys.argv[2] != "--chapters-and-headings":
    print("\nInvalid syntax: {}\n".format(cmd) + usage)
    sys.exit(1)

print("\n")
print("\nSTART: argument processing")
print("\n**CHAPTERS-AND-HEADINGS found")

# process all arguments
CHAPTERS = {}
NAMES = []
stage="CHAPTERS-AND-HEADINGS"
for i in range(3,N):
  name=sys.argv[i]
  # print("stage={} name={}".format(stage,name))
  # --options
  if name == "--chapters-and-headings":
    stage="CHAPTERS-AND-HEADINGS"
    print("\n**CHAPTERS-AND-HEADINGS found")
  elif name == "--branches":
    stage="BRANCHES"
    print("\n**BRANCHES found")
  elif name == "--headings":
    stage="HEADINGS"
    print("\n**HEADINGS found")
  else:
    # words
    if stage == "CHAPTERS-AND-HEADINGS":
      NAMES.append(name)
      print("  inside CHAPTERS-AND-HEADINGS name={}".format(name))
      chapter = {
        "name": name,
        "skip-readme": False,
        "is-heading": False,
      }   
      CHAPTERS[name] = chapter
    elif stage == "BRANCHES":
      print("  inside BRANCHES name:{}".format(name))
      CHAPTERS[name]["skip-readme"] = True
    elif stage == "HEADINGS":
      print("  inside HEADINGS name={}".format(name))
      CHAPTERS[name]["is-heading"] = True
    else:
      print("  say what?")

if len(NAMES) == 0:
  print("\nNo CHAPTERS specified--Nothing to do: {}\n".format(cmd) + usage)
  sys.exit()

print("\nDONE: argument processing\n\n")


print("NAMES={}\n".format(NAMES))
  
  
CHILDREN = []
Nchapters=0
print("START: Create list of children and indices (actual chapters, no headings)")
for name in NAMES:
  chapter = CHAPTERS[name]
  if chapter["is-heading"] == False:
    Nchapters+=1
    chapter["index"] = Nchapters
    print("  {}. {}".format(Nchapters,name))
    CHILDREN.append(name)
print("DONE: Create list of children and indices \n")
    
print("CHILDREN={}\n".format(CHILDREN))
#print("CHAPTERS={}".format(CHAPTERS))

  

#############################################################
# read input files
#############################################################

# read in version tag from tag file
lines = []
fn=TAG_FILE
print("START: Read version tag file={}".format(fn))
with open(fn, 'r') as f:
  print("  FOUND: "+fn)
  for line in f:
    lines.append(line.rstrip())
tag = lines[0].strip()
print("DONE: Read version tag={}\n".format(tag))

# Set Document title
#MATHQ_TITLE = "# Mathématiques {}\n".format(tag)
#MATHQ_TITLE = "[<h1 style='border: 2px solid; text-align: center'>Mathématiques {}</h1>](../README.md)".format(tag)
MATHQ_TITLE = "<h1 style='border: 2px solid; text-align: center'><a href='../README.md'>Mathématiques {}</a></h1>".format(tag)

# read in body file
lines = []
fn = "body.temp.md"
print("START: Read body file={}".format(fn))
with open(fn, 'r') as f:
  print("  FOUND: "+fn)
  body = f.read()
print("DONE: Read body='{}'{}\n".format(body[:20].replace('\n', ' '),"" if len(body) < 20 else "..."))

fn = "title.src.md"
print("START: Read title file={}".format(fn))
if os.path.exists(fn):
  print("  FOUND: "+fn)
  with open(fn) as f:
    title_text = f.read()
print("DONE: Read title title_text={}\n".format(title_text))

# read in node.json, if exists
data_file = "node.json"
fn=data_file
print("START: Read node.json file={}".format(fn))
if os.path.exists(fn):
  print("  FOUND: "+fn)
  with open(fn) as f:
    node = json.load(f)
    node["prefix"] = node["prefix"].replace("Chapter ","")
else:
  print("  NOT FOUND: "+fn+". Assuming Top level of User Manual and using default node.")
  node = {
    "title": title_text,
    "prefix": "Chapter ",
    "level": 1,
    "header": MATHQ_TITLE,
  }
print("Done: Read node.json node={}\n".format(str(node)))


# read in chapter/title.src.md for each chapter
print("START: Read title text from files")
for name in NAMES:
  chapter = CHAPTERS[name]
  # print("  {}".format(chapter))
  if chapter["is-heading"] == True:
    fn = name
  else:
    fn = name+"/title.src.md"
  lines = []
  print("  name={}, file={}".format(name,fn))
  with open(fn, 'r') as f:
    for line in f:
      lines.append(line.rstrip())
  if len(lines): 
    title = lines[0].strip()
  else:
    title = "    ** '{}' not found.".format(fn)  
  chapter["title"] = title
  print("    title={}".format(title))
print("DONE: Read title text from files\n")



#############################################################
# complete the rest of CHAPTERS node
#############################################################

# create rest of node for each child
print("START: create rest of node data for each child (actual chapters)")
for name in CHILDREN:
  chapter = CHAPTERS[name]
  index = chapter["index"]
  chapter["version"] = tag
  chapter["prefix"] = node["prefix"] + str(index) + "."
  chapter["src"] = name+"/template.md"
  chapter["dest"] = name+"/README.md"
  chapter["level"] = node["level"] +1
  chapter["parent"] = node
  # print("  name={}, chapter={}".format(name,chapter))
  print("  name={} processed".format(name))
print("DONE: create rest of node data for each child (actual chapters)\n")


# add prev,next for chapter
print("START: create prev/next for each child (actual chapters)")
for i in range(Nchapters):
  name = CHILDREN[i]
  chapter = CHAPTERS[name]
  if chapter["is-heading"] == False:
    if (i == 0): 
      chapter["prev"] = None
    else:
      chapter["prev"] = CHILDREN[i-1]
    if (i == Nchapters-1): 
      chapter["next"] = None
    else:
      chapter["next"] = CHILDREN[i+1]
    print("  name={} processed".format(name))
print("DONE: create prev/next for each child (actual chapters)\n")



# #############################################################
# # write CHAPTERS to branch.json 
# #############################################################
# delete("branch.json")
# with open('branch.json', 'w') as f:
#   json.dump(CHAPTERS, f,  indent=2)





#############################################################
# write my README.md
#############################################################

header = node["header"]

node_title = ""
if node["level"] == 1:
  node_title = node["title"]
else:
  node_title = node["prefix"] + (len(node["prefix"])>0)*" " + node["title"]
  
top = """

{} {}

""".format("#", node_title)
#""".format(node["level"]*"#", node["prefix"] + (len(node["prefix"])>0)*" " + node["title"])

mytoc = ""
print("START: create TOC")
i=0
for name in CHAPTERS:
  chapter = CHAPTERS[name]
  if chapter["is-heading"] == True:
    text = "**"+chapter["title"]+"**"
    if i > 0:
      text = "<br>"+text
  else:
    link = "[{}]({})".format(chapter["title"], name+"/README.md")
    text = chapter["prefix"]+ " " + link
  print("  name={} processed: {}".format(name,text))
  mytoc += text + "<br>\n"
  i += 1
print("DONE: create TOC\n")

footer = ""

# write to README.md
print("START: write README.md")
delete("README.md")
f = open("README.md", "w")
f.write(header + top + mytoc + body + footer)
f.close()
print("DONE: write README.md\n")




#############################################################
# create header for children
#############################################################
menu = """

<details>

<summary>{}</summary>

{}

</details>

"""
print("START: create child headers")
for name in CHILDREN:
  chapter = CHAPTERS[name]
  title = node["title"]
  print("  child={}".format(name))
  # print("  chapter={}".format(chapter))
  file = "../README.md"
  link = "[{}]({})".format(node_title, file)
  toc = "# " + link + "<br>\n"
  for name2 in CHILDREN:
    chapter2 = CHAPTERS[name2]
    if chapter2["is-heading"] == False:
      # print("    name2={}".format(name2))
      if name == name2:
        line = chapter["prefix"]+ " _" + chapter["title"] + "_ <br>\n"      
        if chapter["index"] == 1:
          line = "\n" + line
      else: 
        link = "[{}]({})".format(chapter2["title"], "../"+name2+"/README.md")
        line = chapter2["prefix"]+ " " + link + "<br>\n"
      toc += line
  chapter["header"] = re.sub('\.\./README', '../../README', node["header"]) + menu.format(title, toc)
print("DONE: create child headers\n")


#############################################################
# create footer for children
#############################################################
footer = """

| ⇦ <br />{}  | {}<br />{}<br /><img width=1000/> | ⇨ <br />{}   |
| ------------ | :-------------------------------: | ------------ |

"""
print("START: create child footers")
for name in CHILDREN:
  chapter = CHAPTERS[name]
  print("  child={}".format(name))
  # print("  chapter={}".format(chapter))
  mytitle = chapter["title"]
  parent = "[{}]({})".format(node["title"], "../README.md")
  nameP = chapter["prev"]
  if nameP == None:
    linkP = ""  
  else:
    chapterP = CHAPTERS[nameP]
    linkP = "[{}]({})".format(chapterP["title"], "../"+nameP+"/README.md")
  nameN = chapter["next"]
  if nameN == None:
    linkN = ""  
  else:
    chapterN = CHAPTERS[nameN]
    linkN = "[{}]({})".format(chapterN["title"], "../"+nameN+"/README.md")
  chapter["footer"] = footer.format(linkP, parent, mytitle, linkN)
print("DONE: create child footers\n")

    
#############################################################
# write chapter node to chapter/node.json
#############################################################
print("START: write child node.json files")
for name in CHILDREN:
  fn = name+"/node.json"
  delete(fn)
  with open(fn, 'w') as f:
    json.dump(CHAPTERS[name], f,  indent=2)
print("DONE: write child node.json files\n")


sys.exit()

