from itertools import combinations

def beautiful_array(N):
    def divide_and_conquer(arr):
        if len(arr) < 3:
            return arr
        A = set(arr)
        B = set()
        N = len(arr)
        for i in range(N):
            for j in range(i + 1, N):
                if arr[i] not in A or arr[j] not in A:
                    continue
                target = (arr[i] + arr[j])
                if not (target % 2) and (target // 2) in A:
                    A.remove(target // 2)
                    B.add(target // 2)
        print(A, B)
        if not B:
            return list(A)
        else:
            return divide_and_conquer(list(A)) + divide_and_conquer(list(B))
    
    return divide_and_conquer(list(range(1, N + 1)))


def check_beautiful(arr):
    for i, j in combinations(range(len(arr)), 2):
        x = arr[i] + arr[j]
        for k in range(i + 1, j):
            if 2 * arr[k] == x:
                return False
    return True


# if __name__ == '__main__':
#     for n in range(2, 400):
#         res = beautiful_array(n)
#         if not check_beautiful(res):
#             print(f'Failed at N={n}')