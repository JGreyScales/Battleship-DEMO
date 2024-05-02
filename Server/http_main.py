
from http.server import BaseHTTPRequestHandler, HTTPServer
from serverHelper import ServerHelper
from GameHelper import GameHelper
import json, sys



class httpServ(BaseHTTPRequestHandler): 

    # the basic process that all queries will undergo
    def basicProcess(server, isPost) -> list:
        #break down the query into its components using parseQuery
        queryItems, path = ServerHelper.parseQuery(server.path)
        print(queryItems, path)
        # ensure authentication of the query, function handles return protocol
        if ServerHelper.handleAuth(server, path) == 401: return

        # Generate the gamemethod based on the path of the HTTP request
        method = getattr(GameHelper, path[1:])
        returnData = method(isPost, queryItems)
        return returnData
    
    def do_GET(self) -> None:  
        returnData = httpServ.basicProcess(self, False)

        if returnData[0] == 200:
            content = returnData[1]
            self.protocol_version = 'HTTP/1.1'
            self.send_response(200)
            self.send_header(keyword="Content-type", value="text/html")
            self.send_header("Content-length", sys.getsizeof(content))
            self.end_headers()
            self.wfile.write(bytes(content, "utf-8"))
        else:
            json_data = {'parsedData': True}
            json_to_pass = json.dumps(json_data)
            self.wfile.write(json_to_pass.encode('utf-8'))
    
    def do_POST(self) -> None:
        returnData = httpServ.basicProcess(self, True)
        if returnData[0]:
            json_data = {'successs': True}
            json_to_pass = json.dumps(json_data)
            self.wfile.write(json_to_pass.encode('utf-8'))
            return
    
        json_data = {'successs': False}
        json_to_pass = json.dumps(json_data)
        self.wfile.write(json_to_pass.encode('utf-8'))


  
def run(server_class=HTTPServer, handler_class=httpServ, port=8008):
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    
    print(f'Starting httpd on port {port}...')
    # begin serving on port 8008
    httpd.serve_forever()
    
# initiate the server
run()