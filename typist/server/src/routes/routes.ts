import {Response, Request} from "express"

export let getApi = (req: Request, res: Response) => {
  res.status(200).send("Welcome to RESTful API")
}
