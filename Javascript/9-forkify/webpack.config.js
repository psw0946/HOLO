const path = require('path'); // built-in node module
const HtmlWebpackPlugin = require('html-webpack-plugin'); // src 에 있는 index.html 을 알아서 dist 로 복사해주도록

module.exports = {
    entry: ['@babel/polyfill', './src/js/index.js'], // where webpack will start the bundling
    output: {
        path: path.resolve(__dirname, 'dist'), // should be absolute path, __dirname: current directory, path 는 dist 까지만... dist 에 배포할 파일 다 들어있으므로..
        filename: 'js/bundle.js'
    }, // where to save the bundled file
    // mode: 'development' //
    devServer: {
        contentBase: './dist'
    },
    plugins: [
        new HtmlWebpackPlugin({
            filename: 'index.html',
            template: './src/index.html' // 무엇을 복사할 것인가
        })
    ],
    module: {
        rules: [
            {
                test: /\.js$/,
                exclude: /node_modules/,
                use: {
                    loader: 'babel-loader'
                }
            }
        ]
    }
};