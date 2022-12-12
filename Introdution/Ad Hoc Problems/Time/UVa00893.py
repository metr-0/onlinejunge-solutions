from datetime import datetime, timedelta

while True:
    delta, d, m, y = map(int, input().split())
    if y == 0:
        break

    date = datetime(y, m, d) + timedelta(days=delta % 146_097)
    print(date.day, date.month, date.year + (delta // 146_097) * 400)
