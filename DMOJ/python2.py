class Magic(object):
    def method(self):
        print('Success' if self is None else 'Fail')

print(Magic.method(None))
