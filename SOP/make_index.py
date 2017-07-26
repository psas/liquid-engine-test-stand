#!/usr/bin/env python
import glob
import os

page = """---
layout: base
title: PSAS Procedure Book
---

# Procedures:

"""

chapters = []

for chapter in glob.iglob('./*-*.markdown'):
    fileName, fileExtension = os.path.splitext(os.path.basename(chapter))
    chapters.append(fileName)

chapters.sort(key=lambda n: int(n.split('-')[0]))

with open('index.markdown', 'w') as index:
    for chapter in chapters:
        n, title = chapter.split('-')
        page += " 1. [{0}]({1}.html)\n".format(title, chapter)

    index.write(page+"\n")
