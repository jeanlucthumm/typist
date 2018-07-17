import * as express from "express"
import * as bodyParser from "body-parser"

import * as routes from "./routes/routes"

const app = express()

app.use(bodyParser.json())
app.use(bodyParser.urlencoded({extended: true}))

app.get('/', routes.getApi)

app.listen(4000, () => {
  console.log("app running on port 4000")
})

