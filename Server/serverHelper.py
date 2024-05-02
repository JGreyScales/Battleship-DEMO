allowedPostPaths = ["/leaderboard", "/game", "/gameStart"]

class ServerHelper:
    def parseQuery(path: str, returnQueries = {}) -> list:
        print(path)
        queries = path[path.find("?") + 1:].split("&")

        for query in queries:
            delimiter = query.find("=")
            returnQueries[query[:delimiter]] = query[delimiter + 1:]
        return [returnQueries, path[:path.find("?")]]
    
    def handleAuth(server, path) -> int:
        if path not in allowedPostPaths:return 401
        return 200