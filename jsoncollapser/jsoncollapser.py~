"""
How to use:

complicated_dict = {"dict1key": {"dict2key": [{"dict3key": {"tell":"me"}}]}}
one_level_dict = makeSimpleDict(complicated_dict)
print one_level_dict

"""
def makeSimpleDict(complex_dict):
    """
    @param complex_dict : a python dict that might have inner dicts and arrays OR
    a python list that might have inner dicts and arrays OR
    a python object that's neither list of dict
    
    @return plain_dict : plain dict that has only one level or a plain python object
    """
    # make plain dict that you will return
    plain_dict = {} 

    if isinstance(complex_dict, dict):
        # if complex_dict is a dict
        # loop through the keys of this complex dict
        sawComplex = False
        for complex_key in complex_dict:
            # if complex_dict[complex_key] is a dict
            if isinstance(complex_dict[complex_key], dict):
                sub_dict = complex_dict[complex_key]
                # loop through the keys of this sub_dict
                sawComplex = True
                for sub_key in sub_dict:
                    plain_dict[complex_key+"."+sub_key] = makeSimpleDict(sub_dict[sub_key])
            elif isinstance(complex_dict[complex_key], list):
                if not isComplexList(complex_dict[complex_key]):
                    plain_dict[complex_key] = getStrFromList(complex_dict[complex_key])
                else: 
                    sawComplex = True
                    for i in range(len(complex_dict[complex_key])):
                        plain_dict[complex_key+"["+str(i)+"]"] = makeSimpleDict(complex_dict[complex_key][i])
            else:
                plain_dict[complex_key] = makeSimpleDict(complex_dict[complex_key])
        if sawComplex:
            return makeSimpleDict(plain_dict)
        else:
            return plain_dict
    else:
        # if not a dict
        if isinstance(complex_dict, list):
            # if complex_dict is a list
            
            # is complex_dict a list
            # that contains a dict or an inner list?
            if not isComplexList(complex_dict):
                accum = getStrFromList(complex_dict)
                plain_dict = accum
            else:
                # loop through the complex_dict
                for i in range(len(complex_dict)):
                    plain_dict["["+str(i)+"]"] = makeSimpleDict(complex_dict[i])
            return makeSimpleDict(plain_dict)                        
        else:
            # if neither a list or a dict
            return unicode(complex_dict)
                    
                    
def isComplexList(ls):
    for each in ls:
        if isinstance(each, dict) or isinstance(each, list):
            return True
    return False
    
def getStrFromList(ls):
    if isinstance(ls, list):
        return ", ".join([unicode(each) for each in ls])
    else:
        return ls
    

complicated_dict = {"dict1key": {"dict2key": [{"dict3key": {"tell":"me"}}]}}
one_level_dict = makeSimpleDict(complicated_dict)
print one_level_dict
