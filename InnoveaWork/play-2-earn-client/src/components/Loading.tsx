import React from 'react'

interface LoaderOverlayProps {
    isLoading: boolean;
}



const LoaderOverlay: React.FC<LoaderOverlayProps> = ({ isLoading }) => {
    if (!isLoading) {
        return null;
    }



    return (
        <div className="fixed z-50 inset-0 flex items-center justify-center">
            <div className="animate-spin rounded-full h-32 w-32 border-t-2 border-b-2 border-purple-500"></div>
        </div>
    );
};

export default LoaderOverlay