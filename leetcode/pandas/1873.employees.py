import pandas as pd

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees.apply(
        lambda x: x['salary'] if x['employee_id'] % 2 and not x['name'].startswith('M') else 0,
        axis = 1
    )
    df = employees[['employee_id', 'bonus']].sort_values('employee_id')


    return df

# *employees['bonus'] 获取表的某一列
# *用带有 axis=1 参数的 apply()操作所选列的每一行,x即是迭代每一行（series)
# *lambda函数：匿名函数，只允许包含一个表达式，不能包含复杂语句，该表达式的运算结果就是函数的返回值
