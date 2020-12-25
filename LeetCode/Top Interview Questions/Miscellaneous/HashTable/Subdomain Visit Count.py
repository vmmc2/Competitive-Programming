class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        d = {}
        answer = []
        
        for element in cpdomains:
            l = element.split(" ")
            count = int(l[0])
            l2 = l[1].split(".")
            if len(l2) == 2:
                s1 = l2[-1]
                s2 = l2[-2] + "." + l2[-1]
                if s1 not in d:
                    d[s1] = count
                else:
                    d[s1] += count
                if s2 not in d:
                    d[s2] = count
                else:
                    d[s2] += count
            elif len(l2) == 3:
                s1 = l2[-1]
                s2 = l2[-2] + "." + l2[-1]
                s3 = l2[-3] + "." + l2[-2] + "." + l2[-1]
                if s1 not in d:
                    d[s1] = count
                else:
                    d[s1] += count
                if s2 not in d:
                    d[s2] = count
                else:
                    d[s2] += count
                if s3 not in d:
                    d[s3] = count
                else:
                    d[s3] += count
        for key,value in d.items():
            answer.append(str(value) + " " + key)
        return answer
