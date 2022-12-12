from datetime import datetime, timedelta

SIGNS = ["capricorn", "aquarius", "pisces", "aries", "taurus", "gemini",
    "cancer", "leo", "virgo", "libra", "scorpio", "sagittarius"]


def get_sign_i(date):
    if date.month == 12 and date.day >= 23:
        return 0
    if date.month in [1, 3, 4] and date.day >= 21 or \
        date.month == 2 and date.day >= 20 or \
        date.month in [5, 6, 8] and date.day >= 22 or \
        date.month in [7, 11] and date.day >= 23 or \
        date.month in [9, 10] and date.day >= 24:
        return date.month
    return date.month - 1


def main():
    delta = timedelta(weeks=40)
    for i in range(1, int(input()) + 1):
        date = datetime.strptime(input(), "%m%d%Y") + delta
        print(f"{i} {date.strftime('%m/%d/%Y')} {SIGNS[get_sign_i(date)]}")

main()
