import {db} from "../db.js";
import jwt from "jsonwebtoken";
import { response } from "express";

export const getPosts = (req,res) => {
    
    const q = `
    SELECT * 
    FROM posts p 
    WHERE ( 
            p.college LIKE ? AND 
            p.role LIKE ? AND 
            p.company LIKE ? AND 
            p.cat LIKE ? AND 
            p.type LIKE ? AND 
            p.experience LIKE ? AND 
            p.status LIKE ? AND 
            p.level LIKE ?
          ) 
            AND 
          (
            p.college LIKE ? OR 
            p.role LIKE ? OR 
            p.company LIKE ? OR 
            p.cat LIKE ? OR 
            p.type LIKE ? OR 
            p.experience LIKE ? OR 
            p.status LIKE ? OR 
            p.level LIKE ?
          )  
    ORDER BY p.date desc`;

      const Filtervalues = [
        req.query.college ? req.query.college : "%",
        req.query.role ? req.query.role : "%",
        req.query.company ? req.query.company : "%",
        req.query.cat ? req.query.cat : "%",
        req.query.type ? req.query.type : "%",
        req.query.experience ? req.query.experience : "%",
        req.query.status ? req.query.status : "%",
        req.query.level ? req.query.level : "%",
      ]

      const Searchvalues = [
        req.query.search ? `%${req.query.search}%` : "%",
        req.query.search ? `%${req.query.search}%` : "%",
        req.query.search ? `%${req.query.search}%` : "%",
        req.query.search ? `%${req.query.search}%` : "%",
        req.query.search ? `%${req.query.search}%` : "%",
        req.query.search ? `%${req.query.search}%` : "%",
        req.query.search ? `%${req.query.search}%` : "%",
        req.query.search ? `%${req.query.search}%` : "%",
      ]

      console.log(req.query);
      console.log(Filtervalues);
      console.log(Searchvalues);
      db.query(q,[...Filtervalues, ...Searchvalues], (err,data)=> {
        // console.log(res);
        if (err) return res.status(500).send(err);

        return res.status(200).json(data);
      })
}

export const filterPost = (req,res) => {
  console.log(req.query)
  const values = [
    req.query.college ? req.query.college  : "%",
    req.query.role ? req.query.role : "%",
    req.query.company ? req.query.company : "%",
    req.query.cat ? req.query.cat : "%",
    req.query.type ? req.query.type : "%",
    req.query.experience ? req.query.experience : "%",
    req.query.status ? req.query.status : "%",
    req.query.level ? req.query.level : "%",
  ]

  // console.log(values);
  const q = `SELECT DISTINCT p.${req.query.filterType} FROM posts p WHERE p.college LIKE ? AND p.role LIKE ? AND p.company LIKE ? AND p.cat LIKE ? AND p.type LIKE ? AND p.experience LIKE ? AND p.status LIKE ? AND p.level LIKE ?`
  db.query(q,[...values], (err,data) => {
      if (err) return res.status(500).json(err);

      return res.status(200).json(data);
  })

}

export const getPost = (req,res) => {
    const q = "SELECT u.name, p.role,p.company,p.ctc,p.college,p.type,p.experience,p.status,p.level,p.desc,p.img, u.img AS userImg, p.date, p.cat, p.img FROM users u  LEFT JOIN posts p ON u.id = p.uid WHERE p.id = ? ORDER BY p.date desc"

    db.query(q,[req.params.id], (err,data) => {
      if (err) return res.status(500).send(err);

        return res.status(200).json(data[0]);
    })
}


export const deletePost = (req,res) => {
  const token = req.cookies.access_token;
  if(!token) return res.status(401).json("Not authenticated!");

  jwt.verify(token,"jwtkey", (err, userInfo)=>{
    if(err) return res.status(403).json("Token is not valid!");

    const postId = req.params.id;

    const q = "SELECT * FROM posts WHERE id=? AND uid=?";
    // console.log(postId,userInfo.id);
    db.query(q,[postId, userInfo.id], (err,data)=> {
      
      if (err) return res.status(403).json("You can delete only your post!");
      if (!data.length) return res.status(403).json("You can delete only your post!");
      // console.log(data);
      const q = "DELETE FROM posts WHERE id=? AND uid=?";

      db.query(q,[postId, userInfo.id], (err,data)=> {
        if (err) return res.status(403).json("You can delete only your post!");

        return res.json("Post has been deleted!");
      })
    })
  })
}

export const addPost = (req,res) => {

  const token = req.cookies.access_token;
  if(!token) return res.status(401).json("Not authenticated!");

  jwt.verify(token,"jwtkey", (err, userInfo)=>{
    if(err) return res.status(403).json("Token is not valid!");

    const q = "INSERT INTO posts(`uid`,`role`,`company`,`ctc`,`college`,`type`,`experience`,`status`,`level`,`desc`,`img`,`date`,`cat`) VALUES(?)";

    const values = [
      userInfo.id,
      req.body.role,
      req.body.company,
      req.body.ctc,
      req.body.college,
      req.body.type,
      req.body.experience,
      req.body.status,
      req.body.level,
      req.body.desc,
      req.body.img,
      req.body.date,
      req.body.cat,
    ]
    // console.log(values);
    db.query(q,[values],(err,data) => {

      if (err) return res.status(500).json(err);
      return res.json("Post has been successfully created.");
    })
  });
}

export const updatePost = (req,res) => {
  const token = req.cookies.access_token;
  if(!token) return res.status(401).json("Not authenticated!");

  jwt.verify(token,"jwtkey", (err, userInfo)=>{
    if(err) return res.status(403).json("Token is not valid!");

    const postId = req.params.id;
    const q = "UPDATE posts SET `role`=?,`company`=?,`ctc`=?,`college`=?,`type`=?,`experience`=?,`status`=?,`level`=?,`desc`=?,`img`=?,`cat`=? WHERE `id`=? AND `uid`=?";

    const values = [
      userInfo.id,
      req.body.company,
      req.body.ctc,
      req.body.college,
      req.body.type,
      req.body.experience,
      req.body.status,
      req.body.level,
      req.body.desc,
      req.body.img,
      req.body.cat,
    ]

    db.query(q,[...values, postId, userInfo.id],(err,data) => {
      if (err) return res.status(500).json(err);
      return res.json("Post has been updated.");
    })
  });
}


