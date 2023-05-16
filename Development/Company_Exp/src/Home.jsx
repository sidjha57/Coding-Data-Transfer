import CompanyList from "./CompanyList";
import useFetch from "./useFetch";


const Home = () => {
  const {
    data: companies,
    isPending,
    error,
  } = useFetch(`http://localhost:8000/companies`);

  // const handleDelete = (id) => {
  //     const newcompanies = companies.filter(blog => blog.id !== id);
  //     setcompanies(newcompanies);
  // }

  return (
    <div className="home">
      {error && <div>{error}</div>}
      {isPending && <div>Loading...</div>}
      {companies && <CompanyList companies={companies} title="All Companies" />}{" "}
    </div>
  );
}
 
export default Home;