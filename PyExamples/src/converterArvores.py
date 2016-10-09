#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# List to tree conversion algorithm in Python.
# Copyright (C) 2012  Gonzalo Exequiel Pedone
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with This program. If not, see <http: licenses="" www.gnu.org="">.
 
# makeTree() is recursive.
def makeTree(elements=[]):
    elementsTree = []
    index = 0
 
    while index < len(elements):
        # If the next level is greater than current...
        if index + 1  < len(elements) and \
           elements[index][0] < elements[index + 1][0]:
            # Finds the first and the last index of the direct descendants of
            # the current level.
            level = elements[index][0]
            frm = index + 1
 
            while index + 1  < len(elements) and \
                  elements[index + 1][0] != level:
                index += 1
 
            to = index + 1
 
            # Create a new list with the descendants elements, resolve it, and
            # append as child.
            elementsTree.append(elements[frm - 1][1:] +
                                [makeTree(elements[frm: to])])
        # Just append as is to the list without children elements.
        else:
            # Remove the first item.
            elementsTree.append(elements[index][1:] + [[]])
 
        index += 1
 
    return elementsTree
 
# This is the raw xml code:
#
# <stream:stream from="juliet@jabber.org" to="jabber.org">
#     <stream:features>
#         <mechanisms>
#             <mechanism>
#                 data1
#             </mechanism>
#             <mechanism>
#                 data2
#             </mechanism>
#             <mechanism>
#                 data3
#             </mechanism>
#         </mechanisms>
#         <compression xmlns="http://jabber.org/features/compress">
#             <method>
#                 data4
#             </method>
#         </compression>
#         <ver>
#             <optional>
#         </optional></ver>
#     </stream:features>
# </stream:stream>
#
# This is just an example of the type of structures that you can parse with this
# algorithm.
#
# You must create a list of lists, each children list must be in the same order
# in which appears in the original structure.
# The first item in each children list must contains the level of the element
# (line) in the original structure,
# The rest of the items can contains any number and type of variables.
 
l = [[0, 'stream:stream', {'from': 'juliet@jabber.org', 'to': 'jabber.org'}],
     [1, 'stream:features'],
     [2, 'mechanisms'],
     [3, 'mechanism'],
     [4, 'data1'],
     [3, 'mechanism'],
     [4, 'data2'],
     [3, 'mechanism'],
     [4, 'data3'],
     [2, 'compression', {'xmlns': 'http://jabber.org/features/compress'}],
     [3, 'method'],
     [4, 'data4'],
     [2, 'ver'],
     [3, 'optional']]
 
print(makeTree(l))
 
# The output will be something like this:
#
# [['stream:stream', {'from': 'juliet@im.example.com', 'to': 'im.example.com'},
#     [['stream:features',
#         [['mechanisms',
#             [['mechanism',
#                 [['data1', []]]],
#             ['mechanism',
#                 [['data2', []]]],
#             ['mechanism',
#                 [['data3', []]]]]],
#         ['compression', {'xmlns': 'http://jabber.org/features/compress'},
#             [['method',
#                 [['data4', []]]]]],
#         ['ver',
#             [['optional', []]]]]]]]]
