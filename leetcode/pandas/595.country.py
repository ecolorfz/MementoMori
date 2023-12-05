#DataFrame 是一种二维标签数据结构，其中的列可能具有不同的类型。
#你可以把它想象成电子表格或 SQL 表，或者 Series 对象的 dict


import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    df = world[(world['area'] >= 3000000) | (world['population'] >= 25000000)]
     
    return df[['name','population','area']]