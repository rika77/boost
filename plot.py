# -*- coding: utf-8 -*-

# input : n, coordinates
# output : graph
import numpy as np
import matplotlib.pyplot as plt
from shapely import geometry as geo
n =int(input())
ps = []
for i in range(n):
    a, b = map(float, input().split())
    p = geo.Point(a,b)
    ps.append(p)

# A new window
fig = plt.figure()
# Add a subplot
ax = fig.add_subplot(111)
poly = plt.Polygon([[p.x, p.y] for p in ps])
ax.add_patch(poly)

plt.xlim(0, 6)
plt.ylim(0, 6)
plt.show()

