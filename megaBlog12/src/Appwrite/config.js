import conf from "../conf/conf";
import { Databases,Client,ID,Query,Storage } from "appwrite";
export class Service{
  client= new Client();
  databases;
  bucket;

  constructor(){
    this.client
      .setEndpoint(conf.appwriteUrl) 
      .setProject(conf.appwriteProjectID);
      this.databases=new Databases(this.client);
      this.bucket=new Storage(this.client)
  }
  async createPost({title,slug,featuredImg,status,contened,userId}){
    try {
      return await this.databases.createDocument(
        conf.appwriteDatabaseID,
        conf.appwriteCollectionID,
        slug,
        {
          title,
          featuredImg,
          status,
          contened,
          userId,
        }

      )
    } catch (error) {
      throw error;
    }
  }

  async updatePost(slug,{title,featuredImg,status,contened}){
    try {
      return await this.databases.createDocument(
        conf.appwriteDatabaseID,
        conf.appwriteCollectionID,
        slug,
        {
          title,
          featuredImg,
          contened,
          status,
        }
      )
    } catch (error) {
      throw error;
    }
  }

  async deletePost(slug){
    try {
      await this.databases.deleteDocument(
        conf.appwriteDatabaseID,
        conf.appwriteCollectionID,
        slug
        
      )
      return true;
    } catch (error) {
      throw error;
      return false;
    }
  }

  async getPost(slug){
    try {
      return await this.databases.getDocument(
        conf.appwriteDatabaseID,
        conf.appwriteCollectionID,
        slug,
      )
    } catch (error) {
      throw error;
      return false;
    }
  }

  async getPost(query=[Query.equal("status","active")]){
    try {
      return await this.databases.listDocuments(
        conf.appwriteDatabaseID,
        conf.appwriteCollectionID,
        query,
      )
    } catch (error) {
      throw error;
      return false;
    }
  }

  async uploadFile(file){
    try {
      return await this.bucket.createFile(
        conf.appwriteBucketID,
        ID.unique(),
        file,
      )
    } catch (error) {
      throw error;
    }
  }

  async deleteFile(fileID){
    try {
      await this.bucket.deleteFile(
        conf.appwriteBucketID,
        fileID,
      )
      return true;
    } catch (error) {
      throw error;
      return false;
    }
  }
  getFilePreview(fileID){
    return this.bucket.getFilePreview(
      conf.appwriteBucketID,
      fileID,
    )
  }
}
const service=new Service();
export default service;