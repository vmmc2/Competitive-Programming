class Solution:
    def reformatDate(self, date: str) -> str:
        d = {"Jan" : "01", "Feb" : "02", "Mar" : "03", "Apr" : "04", "May" : "05", "Jun" : "06",
            "Jul" : "07", "Aug" : "08", "Sep" : "09", "Oct" : "10", "Nov" : "11", "Dec" : "12"}
        l = date.split(" ")
        answer = ""
        # 1) Pegando o ano...
        answer += l[2]
        answer += "-"
        # 2) Pegando o mes...
        answer += d[l[1]]
        answer += "-"
        # 3) Pegando o dia...
        if len(l[0]) == 3:
            answer +=  "0" + l[0][0:1]
        else:
            answer += l[0][0:2]
        return answer
