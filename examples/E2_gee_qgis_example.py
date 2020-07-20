import ee
from ee_plugin import Map

def addNDVI(image):
    return image.normalizedDifference(['B5', 'B4'])

dataset = ee.FeatureCollection('USDOS/LSIB_SIMPLE/2017').filter(ee.Filter.eq('country_co', 'UV'))

collection = ee.ImageCollection('LANDSAT/LC08/C01/T1_TOA') \
        .filterBounds(ee.Geometry.Polygon([[-5,9],
                                        [3,9],
                                        [3,16],
                                        [-5,16]])) \
        .filterDate('2020-01-01', '2020-04-16')


image1 = collection.median()
image2 = image1.clipToCollection(dataset)
ndvi=addNDVI(image2)

ndviParams = {'palette': ['#d73027', '#f46d43', '#fdae61','#fee08b', '#d9ef8b', '#a6d96a', '#66bd63', '#1a9850']}
Map.addLayer(ndvi, ndviParams)
