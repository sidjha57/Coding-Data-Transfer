import React from 'react'
import DataTable from 'react-data-table-component'


const ProductList = ({products}) => {

  const COLUMNS = [
    {
      Header: 'image',
      accessor: `{$images_list[0]}`
    },
    {
      Header: 'Name',
      accessor: 'title'
    },
    {
      Header: 'Brand',
      accessor: 'brand'
    },
    {
      Header: 'Price',
      accessor: 'price'
    },    
  ]

  return (
    <div className='product-list'>
         `{products[0].title}`
        <DataTable />
    </div>
  )

}

export default ProductList;
