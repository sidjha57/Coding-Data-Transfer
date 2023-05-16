import express from "express";
import { addPost, getPost, getPosts, deletePost, updatePost, filterPost} from "../controllers/post.js";

const router = express.Router()

router.get("/", getPosts)
router.get("/filters", filterPost)
router.get("/:id", getPost)
router.post("/", addPost)
router.delete("/:id", deletePost)
router.put("/:id", updatePost)



export default router;