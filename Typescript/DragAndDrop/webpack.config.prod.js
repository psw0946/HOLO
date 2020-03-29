const path = require('path');
const CleanPlugin = require('clean-webpack-plugin');

module.exports = {
  mode: 'production',
  entry: './src/app.ts',
  output: {
    filename: 'bundle.js', // This will be the single javascript file which will be produced in the end.
    path: path.resolve(__dirname, 'dist')
  },
  devtool: 'none', // sourceMap: true 와 같이 브라우저에서 디버깅 쉽게 하도록 해줌.
  module: {
    rules: [
      {
        test: /\.ts$/,
        use: 'ts-loader',
        exclude: /node_modules/
      }
    ]
  },
  resolve: {
    extensions: ['.ts', '.js']
  },
  plugins: [
    new CleanPlugin.CleanWebpackPlugin() // 빌드할 때마다 원래 있던 빌드 파일을 지우고 새로 함.
  ]
};
