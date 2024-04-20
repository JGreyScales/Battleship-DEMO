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
        if path not in allowedPostPaths:
            server.send_response(code=401, message="401 forbidden")
            server.end_headers()
            return 401
        
        server.send_response(code=200, message="message recieved")
        server.send_header(keyword="Content-type", value="application/json")
        server.end_headers()
        return 200