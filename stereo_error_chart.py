#!/usr/bin/python
import math
import numpy as np

resolution_x  = 3600

# in meters
baseline = 0.01

# field of view  in degrees
fov = 120.0;

# in pixels, 0.2 is a good assumption
disparity_error = 0.2

focal_length = resolution_x  / (2 * math.tan(math.radians((fov/2.0))))
print "focal length ", focal_length

print "--------------"

l = np.linspace(0.1, 25, 25)

print 'Disparity', '\t', 'Depth (m)', '\t', 'Error in depth estimate (m)'
print "--------------------------------------"

for disparity in l:
  z = (baseline * focal_length) / disparity
  z_error = (z * z * disparity_error) / (baseline * focal_length)
  #print disparity, '\t', z, '\t', z_error
  #print "%f\t%0.2f\t%0.2f" % disparity, z, z_error
  print "%0.2f \t\t %0.2f \t\t %0.2f" % (disparity, z, z_error)
  

print "--------------------------------------"
