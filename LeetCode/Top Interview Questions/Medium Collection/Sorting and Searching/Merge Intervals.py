class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        result = [] #lista com o resultado
        tam = len(intervals)
        cursor = 0
        end = tam - 1
        while cursor <= end:
            beggin = intervals[cursor][0]
            junction = intervals[cursor][1]
            if cursor == end:
                result.append([beggin,junction])
                break
            cursor += 1
            while True: #tentar juntar os intervals
                if cursor == tam:
                    result.append([beggin,junction])
                    break
                if junction >= intervals[cursor][0]:
                    if junction < intervals[cursor][1]:
                        junction = intervals[cursor][1]
                        cursor += 1
                    else:
                        cursor += 1
                else:
                    result.append([beggin,junction])
                    break
        return result
            
            
            
