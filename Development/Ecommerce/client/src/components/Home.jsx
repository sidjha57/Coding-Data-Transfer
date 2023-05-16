import ProductList from "./ProductList";
import useFetch from "./useFetch";


const Home = () => {
  const {
    data: products,
    isPending,
    error,
  } = useFetch(`http://localhost:8000/products`);


  return (
    <div className="home">
      {error && <div>{error}</div>}
      {isPending && <div>Loading...</div>}
      {/* this is how conditional output works in react */}
      {products && <ProductList products={products}/>}
      {/*We can pass multiple props*/}
      {/* <BlogList blogs={blogs.filter((blog) => blog.author === 'mario')} title="Mario's Blogs"/> */}
    </div>
  );
}
 
export default Home;