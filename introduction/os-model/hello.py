def main():
    x = 0
    for _ in range(10):
        # b = yield 0 or b = yield 1
        b = sys_read()
        x = x * 2 + b

    # left-padded with zeros 
    # to meet the width of 10 characters specified by 010.
    sys_write(f'x = {x:010b}b')
