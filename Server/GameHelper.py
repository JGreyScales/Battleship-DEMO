import json

gameConnections = {}

class GameHelper:
    def reorderList(index, currentList, query):
        newValue = [query["name"], int(query["score"])]
        while index <= len(currentList):
            toBeMovedValue = [currentList[str(index)][0], int(currentList[str(index)][1])]
            currentList[str(index)] = newValue
            newValue = toBeMovedValue
            index += 1

        return currentList

    def leaderboard(isPost: bool, queries: dict) -> list:
        leaderBoardInfo = json.load(open(f"leaderboard.json", "r"))
        playerScore = int(queries["score"])

        for jsonPos in leaderBoardInfo:
            score = leaderBoardInfo[jsonPos][1]
            if playerScore > score:
                json.dump(GameHelper.reorderList(int(jsonPos), leaderBoardInfo, queries), open(f"leaderboard.json", "w"), indent=4)
                return [True, "success"]
            
    # Handles game creation
    def game(isPost: bool, queries: dict) -> int:
        try:
            gameConnections[queries["gamePin"]]
            return 401
        except (KeyError):
            if queries["Hosted"] == "True":
                gameObject = [
                    [None], # player 1 gameboard
                    [None], # player 2 gameboard
                    [queries["userID"], queries["username"]], # player 1 ID and username
                    [None, None] # player 2 ID and username
                ]
                gameConnections[queries["gamePin"]] = gameObject
            else:
                gameConnections[queries["gamePin"]][3] = [queries["userID"], queries["username"]]
            return [200, "success"]