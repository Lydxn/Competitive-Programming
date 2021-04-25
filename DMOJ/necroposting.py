print(abs(__import__('datetime').datetime.strptime(input(), '%Y/%m/%d') -
          __import__('datetime').datetime.strptime(input(), '%Y/%m/%d')).days)
