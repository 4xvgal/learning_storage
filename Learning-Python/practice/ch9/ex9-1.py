print('[원시 데이터]')
print(t, '\n\n')
low_t = t.lower()
t = ''
for word in low_t.split(' '):
    if word == 'kt' or word == 'samsung' or word == 'lg' or word == 'skt':
        t += '* '
    else:
        t += word + ' '
print('[처리된 결과]')
print(t)
